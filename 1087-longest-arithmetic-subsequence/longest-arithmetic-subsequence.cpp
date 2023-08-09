class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> v(n); 
        int res = 2;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];

                res = max(res , 1 + v[j][diff]);

                v[i][diff] = max(2 , 1+v[j][diff]);
            }
        }    
        return res;
    }
};