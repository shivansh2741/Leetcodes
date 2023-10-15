class Solution {
public:
    vector<int> factorial;

    int findfactorial(int n){
        if(n == 0 || n == 1)return 1;

        return factorial[n] = (n*findfactorial(n-1));
    }
    string getPermutation(int n, int k) {
        factorial.resize(n+1,1);
        findfactorial(n);    

        string ans;
        vector<int> vis(n+1,0);
        int index = 1;

        while(index <= n){
            int i = 1;
            while(i <= n){
                if(vis[i]){
                    i++;
                    continue;
                }
                if(k - factorial[n - index] > 0){
                    k = k - factorial[n - index];
                }
                else{
                    vis[i] = 1;
                    break;
                };

                i++;
            }
            ans.push_back(i+'0');
            index++;
        }
        return ans;
    }
};