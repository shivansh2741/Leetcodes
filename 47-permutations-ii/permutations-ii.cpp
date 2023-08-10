class Solution {
public:
    
    void solve(vector<int>& nums,int index,
              vector<vector<int>> &res){
        
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }
        
        set<int> s;
        for(int i=index;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())continue;
            s.insert(nums[i]);
            swap(nums[i],nums[index]);
            solve(nums,index+1,res);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        solve(nums,0,res);
        
        return res;
    }
};