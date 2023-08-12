class Solution {
public:
    int dp[301][301];

    int solve(vector<int>& vec,int i,int j){
        if(i > j)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int cost = 0;
        for(int k=i;k<=j;k++){
            cost = max(cost , vec[k]*vec[i-1]*vec[j+1] 
                                + solve(vec,i,k-1) + solve(vec,k+1,j));
        }
        return dp[i][j] = cost;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        
        vector<int> vec;

        vec.push_back(1);

        for(int i=0;i<n;i++)
            vec.push_back(nums[i]);

        vec.push_back(1);

        return solve(vec,1,n);  
    }
};