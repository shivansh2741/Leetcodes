class DisjointSet{
    public:
    vector<int> size , parent;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int findUPar(int u){
        if(parent[u] == u)return u;
        else return parent[u] = findUPar(parent[u]);
    }

    void UnionBySize(int u,int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if(ult_v == ult_u)return;

        if(size[ult_v] > size[ult_u]){
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
        else{
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DisjointSet ds(n);

        vector<pair<int,pair<int,int>>> edges;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ui = points[i][0] , uf = points[j][0];
                int yi = points[i][1] , yf = points[j][1];

                int manhattan = abs(ui - uf) + abs(yi - yf);
                
                edges.push_back({manhattan , {i,j}});
                
            }
        }

        sort(edges.begin() , edges.end());
        int sum = 0;

        for(auto &it:edges){
            int dist = it.first;
            int node1 = it.second.first;
            int node2 = it.second.second;


            if(ds.findUPar(node1) == ds.findUPar(node2))
                continue;
            else{
                ds.UnionBySize(node1,node2);
                sum += dist;
            }
        }

        return sum;
    }
};