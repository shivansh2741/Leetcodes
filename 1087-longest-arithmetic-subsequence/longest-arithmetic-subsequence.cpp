class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int las = 1;

        int maxi = *max_element(nums.begin() , nums.end());
        int mini = *min_element(nums.begin() , nums.end());
        
        for(int i=(mini - maxi);i<=(maxi - mini);i++){
            int res = 1;
            int difference = i;
            unordered_map<int,int> mp;

            for(int i=0;i<n;i++){
                int ans = 1;

                ans = 1 + mp[nums[i] - difference];  
                res = max(res , ans);  
                
                mp[nums[i]] = ans;
            }

            las = max(las , res);
        }

        return las;
    }
};