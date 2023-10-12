class Solution {
public:
    void merge(vector<int>& nums,int lo,int mid,int hi){
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

        for(int i=0;i<temp.size();i++){
            nums[i + lo] = temp[i];
        }
    }
    void mergeSort(vector<int>& nums,int low,int high){
        if(low >= high)return;

        int mid = low + (high - low)/2;

        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);

        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        mergeSort(nums,0,n-1);

        return nums;    
    }
};