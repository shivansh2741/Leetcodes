class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size() , m = l.size();

        vector<bool> ans(m);

        for(int i=0;i<m;i++){
            int lo = l[i] , hi = r[i];

            if(lo == hi){
                ans[i] = false;
                continue;
            }

            vector<int> copy;
            for(int j=lo;j<=hi;j++){
                copy.push_back(nums[j]);
            }

            sort(copy.begin(),copy.end());

            bool flag = true;
            int diff = copy[1] - copy[0];

            for(int j=1;j<copy.size();j++){
                if(copy[j] - copy[j-1] != diff){
                    flag = false;
                    break;
                }
            }

            ans[i] = flag;
        }
        return ans;
    }
};