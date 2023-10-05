class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int ele , count = 0;

        for(int i=0;i<n;i++){
            if(count == 0)
            {
                ele = nums[i];
            }

            if(ele == nums[i])
            {
                count++;
            }
            else{
                count--;
            }
        }

        int freq = 0;

        for(int i=0;i<n;i++){
            if(ele == nums[i]){
                freq++;
            }
        }

        if(freq > n/2)return ele;
        else return -1;    
    }
};