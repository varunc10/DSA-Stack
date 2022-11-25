class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> next(n,n);
        vector<int> prev(n,-1);
        stack<int> s;
        s.push(n-1);
        next[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(arr[s.top()]<arr[i]){
                next[i]=s.top()-i;
            }
            else{
                while(!s.empty()&&arr[s.top()]>arr[i]){
                    s.pop();
                }
                next[i]=s.empty()?n-i:s.top()-i;
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        s.push(0);
        prev[0]=1;
        for(int i=1;i<n;i++){
            if(arr[s.top()]<arr[i]){
                prev[i]=i-s.top();
            }
            else{
                while(!s.empty()&&arr[s.top()]>=arr[i]){
                    s.pop();
                }
                prev[i]=s.empty()?i+1:i-s.top();
            }
            s.push(i);
        }
        int ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            long long prod=(prev[i]*next[i])%mod;
            prod=(prod*arr[i])%mod;
            ans=(ans+prod)%mod;
        }
        return ans%mod;
    }
};