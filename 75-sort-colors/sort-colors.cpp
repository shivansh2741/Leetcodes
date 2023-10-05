class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0 , mid = 0 , hi = n-1;

        while(hi >= mid){
            if(nums[mid] == 0){
                swap(nums[mid] , nums[lo]);
                lo++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[hi]);
                hi--;
            }
        }   
    }
};