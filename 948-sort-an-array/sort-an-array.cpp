class Solution {
public:
    void heapify(vector<int>& nums,int i,int n){
        int l = 2*i + 1 , r = 2*i + 2;
        int largest = i;

        if(l < n && nums[largest] < nums[l])
            largest = l;
        
        if(r < n && nums[largest] < nums[r])
            largest = r;
        
        if(largest != i){
            swap(nums[largest] , nums[i]);
            heapify(nums,largest,n);
        }
    }

    void buildheap(vector<int>& nums,int n){
        for(int i=n/2;i>=0;i--){
            heapify(nums,i,n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // buildheap(nums,n);

        // for(int i=n-1;i>=0;i--){
        //     heapify(nums,i,n);
        // }

        // reverse(nums.begin(), nums.end());
        // return nums;
        buildheap(nums,n);

        for(int i=n-1;i>=0;i--){
            swap(nums[0] , nums[i]);
            heapify(nums,0,i);
        }    
        return nums;
    }
};