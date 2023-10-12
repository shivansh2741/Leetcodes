class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        if(n == 1)return 0;
        int count = 0;

        int i = n-1;
        while(i >= 0){
            int temp = i , index = i;
            i--;

            while(i >= 0){
                if(nums[i] >= temp - i){
                    index = i;
                }
                i--;
            }
            count++;
            if(index == 0)return count;
            i = index;
        }   
        return count;
    }
};