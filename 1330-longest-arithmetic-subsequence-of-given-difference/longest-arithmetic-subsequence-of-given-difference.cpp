class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        int n = nums.size();
        
        int res = 1;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int ans = 1;

            ans = 1 + mp[nums[i] - difference];  
            res = max(res , ans);  
            
            mp[nums[i]] = ans;
        }

        return res;
    }
};