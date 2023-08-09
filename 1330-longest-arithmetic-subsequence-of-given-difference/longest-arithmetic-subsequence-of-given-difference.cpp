class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        int n = nums.size();
        
        int res = 1;
        map<int,int> mp;

        for(int i=0;i<n;i++){
            int ans = 1;
            if(mp.find(nums[i] - difference) != mp.end()){
                ans = 1 + mp[nums[i] - difference];  
                res = max(res , ans);  
            }
            
            if(mp.find(nums[i]) != mp.end())
                mp[nums[i]] = max(mp[nums[i]] , ans);
            else mp[nums[i]] = ans;
        }

        return res;
    }
};