class Solution {
public:
    void solve(vector<int>& nums,int index,int n,int target,vector<int>& ans,vector<vector<int>>& res){
        if(target < 0)return;
        if(index == n){
            if(target == 0){
                res.push_back(ans);
            }
            return;
        }

        //pick
        ans.push_back(nums[index]);
        solve(nums,index+1,n,target-nums[index],ans,res);

        //notpick
        ans.pop_back();
        while(index+1 < n && nums[index] == nums[index+1]){
            index++;
        }

        solve(nums,index+1,n,target,ans,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<int> ans;
        vector<vector<int>> res;

        solve(nums,0,nums.size(),target,ans,res);
        return res;  
    }
};