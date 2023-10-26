class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0] , maxi = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++){
            int temp = max({maxi*nums[i] , mini*nums[i], nums[i]});
            mini = min({maxi*nums[i] , mini*nums[i], nums[i]});
            maxi = temp;
            ans = max({ans , maxi, mini});
        }   
        return ans; 
    }
};