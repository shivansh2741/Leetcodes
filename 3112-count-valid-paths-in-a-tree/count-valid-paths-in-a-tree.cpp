class DisjointSet{
    public:
    vector<int> parent , size;

    DisjointSet(int n){
        parent.resize(n+3);
        size.resize(n+3,1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int u){
        if(parent[u] == u)return u;
        else return parent[u] = findUPar(parent[u]);
    }

    void UnionBySize(int u,int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if(ult_u == ult_v)return;

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
    vector<int> primes;

    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //sieve
        primes.resize(n+5,1);
        primes[0] = primes[1] = 0;

        for(int i=2;i<=n;i++){
            if(primes[i] == 1){
                for(int j=2*i;j<=n;j+=i){
                    primes[j] = 0;
                }
            }
        }    

        DisjointSet ds(n+2);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0] , v = edges[i][1];
            if(primes[u] == 1 || primes[v] == 1)continue;

            ds.UnionBySize(u,v);
        }

        long long ans = 0;

        for(int i=1;i<=n;i++){
            if(primes[i] == 0)continue;

            long long total = 1;

            for(auto it:adj[i]){
                if(primes[it] == 1)continue;

                long long nodes = ds.size[ds.findUPar(it)];

                ans += (total*nodes);
                total += nodes;
            }
        }
        return ans;
    }
};