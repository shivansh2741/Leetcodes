class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> preSum(n,0);
        preSum[0] = nums[0];

        for(int i=1;i<n;i++){
            preSum[i] = preSum[i-1] + nums[i];
        }  
        int totsum = preSum[n-1];

        if(totsum - preSum[0] == 0)return 0;

        for(int i=1;i<n;i++){
            if(preSum[i-1] == totsum - preSum[i])
                return i;
        }
        return -1;
    }
};