class Solution {
public:
    void solve(int i,int n,int k,vector<int>& ans,vector<vector<int>>& res){
        if(k == 0){
            res.push_back(ans);
            return;
        }
        if(i == n+1){
            return;
        }

        ans.push_back(i);
        solve(i+1,n,k-1,ans,res);

        ans.pop_back();
        solve(i+1,n,k,ans,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> res;

        solve(1,n,k,ans,res);

        return res;        
    }
};