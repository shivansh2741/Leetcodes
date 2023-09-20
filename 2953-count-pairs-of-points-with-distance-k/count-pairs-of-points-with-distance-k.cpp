class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        
        map<pair<int,int>,int> mp;
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int val = 0; val <= 100; val++){
                int x = coordinates[i][0]^val;
                int y = coordinates[i][1]^(k - val);

                if(mp.find({x,y}) != mp.end())
                    ans += mp[{x,y}];
            }
            mp[{coordinates[i][0],coordinates[i][1]}]++;
        }
        return ans;
    }
};