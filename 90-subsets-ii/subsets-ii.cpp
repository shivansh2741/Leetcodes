class Solution {
public:
    void solve(vector<int>& nums,int index,int n,vector<int>& ans,
    vector<vector<int>>& res){

        if(index == n){
            res.push_back(ans);
            return;
        }

        ans.push_back(nums[index]);
        solve(nums,index+1,n,ans,res);

        while(index+1<n && nums[index+1] == nums[index]){
            index++;
        }
        
        ans.pop_back();
        solve(nums,index+1,n,ans,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin() , nums.end());
        vector<int> ans;
        vector<vector<int>> res;

        solve(nums,0,n,ans,res);

        return res;    
    }
};