class Solution {
public:
    void dfs(int node,vector<pair<int,int>> adj[],vector<int>& vis,vector<int>& cost,vector<int>& depth,int &totalCost,int d){

        vis[node] = 1;
        depth[node] = d;

        for(auto it:adj[node]){
            if(!vis[it.first]){
                cost[it.first] = cost[node] + it.second;
                totalCost += it.second;
                dfs(it.first,adj,vis,cost,depth,totalCost,d+1);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            int u = it[0] , v = it[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }    

        vector<int> depth(n,0), cost(n,0), vis(n,0);
        int totalCost = 0;

        dfs(0,adj,vis,cost,depth,totalCost,0);

        vector<int> ans(n,0);
        ans[0] = totalCost;

        for(int i=1;i<n;i++){
            int a = totalCost - cost[i];
            int b = depth[i] - cost[i];

            ans[i] = (a + b);
        }

        return ans;
    }
};