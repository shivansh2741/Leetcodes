class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int last = n-1;
        int distance = 1;

        for(int i=n-2;i>=0;i--){
            if(nums[i] >= distance)
                distance = 1;
            else distance++;
        }    

        if(distance == 1)return true;
        else return false;
    }
};