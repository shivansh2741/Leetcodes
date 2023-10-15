class Solution {
public:
    int dp[17][17];

    bool isPalindrome(string &str , int i , int j){
        if(j <= i)return true;    

        if(dp[i][j] != -1)return dp[i][j];

        if(str[i] != str[j])
            return dp[i][j] = false;
        else return dp[i][j] = isPalindrome(str,i+1,j-1);
    }

    void solve(string& s,int index,vector<string>& partialans,           vector<vector<string>>& ans){

        if(index == s.size()){
            ans.push_back(partialans);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s , index , i)){
                partialans.push_back(s.substr(index,i-index+1));
                solve(s,i+1,partialans,ans);
                partialans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partialans;

        memset(dp,-1,sizeof(dp));

        solve(s,0,partialans,ans);

        return ans;
    }
};