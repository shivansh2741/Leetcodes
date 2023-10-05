class Solution {
public:
    int solve(string& s,string& t,int i,int j,int n,int m,vector<vector<int>> &dp){
        if(i == n || j == m)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = 1 + solve(s,t,i+1,j+1,n,m,dp);
        }
        else{
            return dp[i][j] = max(solve(s,t,i+1,j,n,m,dp) , solve(s,t,i,j+1,n,m,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(text1,text2,0,0,n,m,dp);   
    }
};