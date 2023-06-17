
class DisjointSet{
  public: 
    vector<int> parent, rank;
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        }
    
    
    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxRow=0;
        int maxCol=0;
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow+1+maxCol+1);
        
        unordered_map<int, int> mp;
        for(int i=0; i<stones.size(); i++){
            int nodeRow = stones[i][0];
            int nodeCol = maxRow+1+stones[i][1];
            ds.unionByRank(nodeRow, nodeCol);
            mp[nodeRow]=1;
            mp[nodeCol]=1;
        }
        
        int components=0;
        for(auto it: mp){
            if(ds.findUParent(it.first)==it.first){
                components++;
            }
        }
        
        
        return stones.size()-components;
                
        
    }
};