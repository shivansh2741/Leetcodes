class Solution {
public:
    void solve(vector<int>& nums,int index,int n,vector<int>& ans,set<vector<int>>& st){

        if(index == n){
            vector<int> temp = ans;
            sort(temp.begin() , temp.end());

            st.insert(temp);
            return;
        }

        ans.push_back(nums[index]);
        solve(nums,index+1,n,ans,st);

        ans.pop_back();
        solve(nums,index+1,n,ans,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;
        vector<int> ans;

        solve(nums,0,n,ans,st);    

        vector<vector<int>> res;

        for(auto it:st){
            res.push_back(it);
        }

        return res;
    }
};