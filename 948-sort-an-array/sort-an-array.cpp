class Solution {
public:
    void mergeSorted(vector<int>& nums,int lo,int mid,int hi){
        int i = lo , j = mid+1;

        vector<int> temp;

        while(i <= mid && j <= hi){
            if(nums[i] > nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= hi){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k=lo;k<=hi;k++){
            nums[k] = temp[k-lo];
        }
    }
    void merge(vector<int>& nums,int lo,int hi){
        if(lo == hi)return;

        int mid = (lo + hi)/2;
        merge(nums,lo,mid);
        merge(nums,mid+1,hi);

        mergeSorted(nums,lo,mid,hi);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        merge(nums,0,n-1);    

        return nums;
    }
};