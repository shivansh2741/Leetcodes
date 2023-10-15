class Solution {
public:
    void solve(vector<int>& nums,int n,vector<int>& temp,vector<vector<int>>& res,int bitmask){

        if(bitmask == (1 << n) - 1){
            res.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if((bitmask & (1 << i)) == 0){
                int newmask = bitmask | (1 << i);
                temp.push_back(nums[i]);
                solve(nums,n,temp,res,newmask);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        vector<vector<int>> res;

        solve(nums,n,temp,res,0);

        return res;    
    }
};