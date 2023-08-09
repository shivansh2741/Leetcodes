class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        int res = 1;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){  
            res = max(res ,  mp[nums[i]] = 1 + mp[nums[i] - difference]);  
        }

        return res;
    }
};