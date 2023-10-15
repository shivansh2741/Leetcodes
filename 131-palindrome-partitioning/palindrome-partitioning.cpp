class Solution {
public:
    bool isPalindrome(string s1){
        string s2 = s1;
        reverse(s2.begin() , s2.end());

        return (s1 == s2);
    }
    void solve(string s,int index,int n,vector<string>& ans,
    vector<vector<string>> &res){
        
        if(index == n){
            res.push_back(ans);
            return;
        }

        string temp;
        for(int i = index;i<n;i++){
            temp.push_back(s[i]);

            if(isPalindrome(temp)){
                ans.push_back(temp);
                solve(s,i+1,n,ans,res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> ans;
        vector<vector<string>> res;

        solve(s,0,n,ans,res);

        return res;        
    }
};