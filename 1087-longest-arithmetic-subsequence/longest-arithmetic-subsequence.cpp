class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<int,int>> v(n);
        
        int ans = 2;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];

                if(v[j].find(diff) != v[j].end()){
                    v[i][diff] = 1 + v[j][diff];
                    ans = max(ans , v[i][diff]);
                }
                else{
                    v[i][diff] = 2;
                }
            }
        }
        return ans;    
    }
};