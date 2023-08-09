class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nextsmaller(n,n) , prevsmaller(n,-1);

        for(int i=0;i<n;i++){
            while(st.size() > 0 && arr[i] <= arr[st.top()]){
                st.pop();
            }

            if(st.size() > 0)
                prevsmaller[i] = st.top();
            st.push(i);
        }

        while(st.size())st.pop();

        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && arr[i] < arr[st.top()])
                st.pop();
            
            if(st.size() > 0)
                nextsmaller[i] = st.top();
            
            st.push(i);
        }

        long long res = 0;
        for(int i=0;i<n;i++){
            res += (1LL*((i-prevsmaller[i])*(nextsmaller[i]-i))*arr[i])%mod; 
        }
        return (res+mod)%mod;
    }
};