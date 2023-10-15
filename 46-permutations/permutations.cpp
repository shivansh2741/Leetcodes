class Solution {
public:
    void solve(vector<int>& nums,int n,vector<vector<int>>& res,int i){

        if(i == n){
            res.push_back(nums);
            return;
        }


        // for ith index
        for(int j=i;j<n;j++){
            swap(nums[i] , nums[j]);
            solve(nums,n,res,i+1);
            swap(nums[i] , nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> res;

        solve(nums,n,res,0);

        return res;    
    }
};