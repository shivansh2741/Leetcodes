class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0 , count2 = 0;
        int ele1 = INT_MAX , ele2 = INT_MAX;

        vector<int> res;

        for(int i=0;i<n;i++){
            if(count1 == 0 && ele2 != nums[i]){
                count1++;
                ele1 = nums[i];
            }
            else if(count2 == 0 && ele1 != nums[i]){
                count2++;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i])
                count1++;
            else if(ele2 == nums[i])
                count2++;
            else{
                count1--;
                count2--;
            }
        }

        //check
        count1 = 0,count2 = 0;       
        for(int i=0;i<n;i++){
            if(ele1 == nums[i])count1++;
            if(ele2 == nums[i])count2++;
        }

        if(count1 > n/3)res.push_back(ele1);
        if(count2 > n/3)res.push_back(ele2);

        return res;  
    }
};