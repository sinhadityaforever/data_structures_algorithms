
class DisjointSet{
  public:
    vector<int> parent, rank;
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i =0; i<n; i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findUPar(parent[u]);
    }
    
    void unionByRank(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges=0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                extraEdges++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }
        
        int components=0;
        for(int i=0; i<n; i++){
            if(ds.findUPar(i)==i) components++;
        }
        int ans = components-1;
        if(extraEdges>=ans) return ans;
        return -1;
        
        
        
    }
};