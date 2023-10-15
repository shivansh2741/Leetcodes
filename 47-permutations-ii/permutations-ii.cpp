class Solution {
public:
    
    void solve(vector<int>& nums,int n,set<vector<int>> &st,int i){

        if(i == n){
            st.insert(nums);
            return;
        }


        // for ith index
        for(int j=i;j<n;j++){
            swap(nums[i] , nums[j]);
            solve(nums,n,st,i+1);
            swap(nums[i] , nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> res;
        set<vector<int>> st;

        solve(nums,n,st,0);

        for(auto it:st){
            res.push_back(it);
        }

        return res;   
    }
};