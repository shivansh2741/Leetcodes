class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin() , arr.end());
        arr[0] = 1;

        int i = 1;
        while(i < n){
            while(arr[i] == arr[i-1] + 1){
                i++;
            }
            if(arr[i] > arr[i-1])
                arr[i] = arr[i-1]+1;
            i++;
        }
        return arr[n-1];
    }
};