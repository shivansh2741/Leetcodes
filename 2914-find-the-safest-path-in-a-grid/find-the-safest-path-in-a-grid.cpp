class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size() , m = grid[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({0,i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int delrow[4] = {0,1,0,-1};
        int delcol[4] = {1,0,-1,0};
        
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            
            int distance = it[0];
            int row = it[1];
            int col = it[2];
           
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                dist[nrow][ncol] > distance+1){
                       
                    q.push({distance+1,nrow,ncol});
                    dist[nrow][ncol] = distance+1;
                    
                }
            }
        }
        
        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));

        pq.push({dist[0][0] , 0 ,0});
        vis[0][0] = 0;

        while(!pq.empty()){
            int distance = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];

            pq.pop();
            if(row == n-1 && col == m-1)return distance;

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    !vis[nrow][ncol]){

                    vis[nrow][ncol] = 1;
                    int temp = min(distance , dist[nrow][ncol]);
                    pq.push({temp , nrow,ncol});
                }
            }
        }
        return 0;
    }
};