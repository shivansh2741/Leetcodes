class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> v(n+1,vector<int>(1100,0));

        int ans = 2;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];

                if(v[j][diff+501] == 0){
                    v[i][diff+501] = 2;
                }
                else{
                    v[i][diff+501] = 1 + v[j][diff+501];
                    ans = max(ans , v[i][diff+501]);
                }
            }
        }
        return ans;    
    }
};