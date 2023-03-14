    
class Solution {
public:
    void NSL(vector<int>& v, vector<int>& nsl){
        stack<int> s;
        s.push(0);
        for(int i = 1; i < v.size(); i++){
            while(!s.empty() && v[s.top()] >= v[i]){
                s.pop();
            }
            nsl[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
    }
    void NSR(vector<int>& v, vector<int>& nsr){
        stack<int> s;
        s.push(v.size() - 1);
        for(int i = v.size() - 2; i >= 0; i--){
            while(!s.empty() && v[s.top()] >= v[i]){
                s.pop();
            }
            nsr[i] = s.empty() ? v.size() : s.top();
            s.push(i);
        }
    }
    int MAH(vector<int>& v){
        vector<int> nsl(v.size(), -1), nsr(v.size(), v.size());
        NSL(v, nsl);
        NSR(v, nsr);
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            int ht = min(v[i], nsr[i] - nsl[i] - 1);
            ans = max(ans, ht * ht);
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> v(matrix[0].size());
        int ans = 0;
        for(int j = 0; j < matrix[0].size(); j++){
            v[j] = matrix[0][j] - '0';    
        }
        ans = max(ans, MAH(v));
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j] += 1;
                }
            }
            ans = max(ans, MAH(v));
        }
        return ans;
    }
};