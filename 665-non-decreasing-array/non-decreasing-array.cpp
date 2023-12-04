class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 || n == 2)return true;

        int count = 0;

        for(int i=1;i<n;i++){
            if(nums[i-1] > nums[i]){
                int num = nums[i];
                if(i <= 1 || (i > 1 && num >= nums[i-2])){
                    count++;
                    nums[i-1] = num;
                }
                else{
                    nums[i] = nums[i-1];
                    count++;
                }
            }
        }    

        return (count <= 1);
    }
};