class Solution {
public:
    
    
    void solve(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col, int n, int m){
        if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || grid[row][col]==0) return;
        vis[row][col]=1;
        int dRow[] = {0,1,0,-1};
        int dCol[] = {1,0,-1,0};
        for(int i=0; i<4; i++){
            solve(grid, vis, row+dRow[i], col + dCol[i], n, m);
        }
        }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        solve(grid, vis, i, j, n, m);
                    }
                }
            }
        }
        
        int totalOnes=0;
        int walkableOnes=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) totalOnes++;
                if(vis[i][j]==1) walkableOnes++;
            }
        }
        return totalOnes-walkableOnes;
        
    }
};