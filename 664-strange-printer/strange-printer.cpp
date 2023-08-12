class Solution {
public:
    int dp[101][101];

    int solve(int i,int j,string& s){
        if(i == j)return 1;

        if(dp[i][j] != -1)return dp[i][j];

        int minTurns = INT_MAX;
        for(int k=i;k<j;k++){
            minTurns = min(minTurns , solve(i,k,s) + solve(k+1,j,s));
        }

        if(s[i] == s[j])return  dp[i][j] = minTurns - 1;
        else  return dp[i][j] = minTurns;
    }
    int strangePrinter(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));

        return solve(0,n-1,s);    
    }
};