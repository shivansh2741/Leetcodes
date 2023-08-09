class Solution {
public:
    bool iscycle = false;
    void dfs(int node,stack<int> &s,vector<vector<int>> &adj,
            vector<int> &vis , vector<int> &dfsvis){
      
      vis[node]=1;
      dfsvis[node]=1;
      
      for(auto it:adj[node]){
        if(!vis[it])
          dfs(it,s,adj,vis,dfsvis);
        else if(vis[it]==1 && dfsvis[it]==1){
            iscycle=true;
            return;
        }
      }
      s.push(node);
      dfsvis[node]=0;
    }
  
  
    vector<int> findOrder(int numCourses, vector<vector<int>>&prerequisites)     {
       vector<vector<int>> adj(numCourses);
      
      for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
      }      
      
      vector<int> vis(numCourses,0);
      vector<int> dfsvis(numCourses,0);
      stack<int> s;
      
      for(int i=0;i<numCourses;i++){
        if(!vis[i])
          dfs(i,s,adj,vis,dfsvis);
      } 
      vector<int> res;
      if(iscycle)return res;
      
      while(s.size()!=0){
        res.push_back(s.top());
        s.pop();
      }
      
      return res;
    }
};