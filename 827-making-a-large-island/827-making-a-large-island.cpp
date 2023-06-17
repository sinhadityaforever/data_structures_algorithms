
class DisjointSet{
  public:
    vector<int> parent, size;
    
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    
    
    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node]= findUParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    
};

class Solution {
public:
    

    
    int largestIsland(vector<vector<int>>& grid) {
        int n =  grid.size();
        DisjointSet ds(n*n);
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         v[(i*n)+j] = grid[i][j];
        //     }
        // }
        
        int dr[]={1,0,-1,0};
        int dc[]= {0,1,0,-1};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                for(int k=0; k<4; k++){
                    int nRow = i+dr[k];
                    int nCol = j+dc[k];
                    if(nRow<n && nRow>=0 && nCol<n && nCol>=0 && grid[nRow][nCol]==1){
                        ds.unionBySize(i*n+j, nRow*n+nCol);
                    }
                }
            }
        }
        
        int maxAns=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) continue;
                set<int> s;
                int tmpAns=0;
                 for(int k=0; k<4; k++){
                    int nRow = i+dr[k];
                    int nCol = j+dc[k];
                    if(nRow<n && nRow>=0 && nCol<n && nCol>=0 && grid[nRow][nCol]==1){
                        s.insert(ds.findUParent(nRow*n+nCol));
                    }
                }
                
                for(auto it: s){
                    tmpAns+=ds.size[it];
                }
                maxAns=max(maxAns, tmpAns+1);
                    
            }
        }
        for(int i=0; i<n*n; i++){
            maxAns= max(maxAns, ds.size[ds.findUParent(i)]);
        }
        return maxAns;
        
        
        
        
        
    }
};