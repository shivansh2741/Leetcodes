class Solution {
public:
    typedef pair<int,pair<int,int>> pii;

    int delrow[4] = {0,1,0,-1};
    int delcol[4] = {1,0,-1,0};

    void dfs(vector<vector<int>>& newGrid,int row,int col,int n,int m){
        
        if(row >= n || row < 0 || col >= m || col < 0 || 
        newGrid[row][col] != 1)return;

        newGrid[row][col] = 2;

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            dfs(newGrid,nrow,ncol,n,m);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        vector<vector<int>> newGrid = grid;
        bool flag = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(newGrid[i][j] == 1){
                    flag = true;
                    dfs(newGrid,i,j,n,m);
                    break;
                }
            }
            if(flag)break;
        } 
        
        queue<pii> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(newGrid[i][j] == 1){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        } 

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto it = q.front();
                q.pop();

                int dist = it.first , row = it.second.first,
                col = it.second.second;

                if(newGrid[row][col] == 2)return dist-1;

                for(int i=0;i<4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m
                        && !vis[nrow][ncol]){
                        
                        vis[nrow][ncol] = 1;
                        q.push({dist+1,{nrow,ncol}});
                    }
                }
            }
        }  
        return 0;
    }
};