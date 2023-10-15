class Solution {
public:
    void solve(vector<int>& candidates,int target,int index,int n,vector<int>& ans,vector<vector<int>>& res){
        
        if(target < 0)return;
        if(index == n){
            if(target == 0){
                res.push_back(ans);
            }
            return;
        }
        
        //pick
        ans.push_back(candidates[index]);
        solve(candidates,target-candidates[index],index,n,ans,res);

        //notpick
        ans.pop_back();
        solve(candidates,target,index+1,n,ans,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<int> ans;
        vector<vector<int>> res;

        solve(candidates,target,0,n,ans,res);

        return res;      
    }
};