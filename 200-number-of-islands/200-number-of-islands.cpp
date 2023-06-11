class Solution {
public:
    
    
    void solve(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col, int n, int m){
        if(row>=n || row<0 || col>=m || col<0 || visited[row][col] || grid[row][col]=='0') return;
        visited[row][col]=1;
        int dRow[]= {0,1,0,-1};
        int dCol[]= {1,0,-1,0};
        for(int i=0; i<4; i++){
            solve(grid, visited, row+dRow[i], col+dCol[i], n, m);
            
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int ans =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    solve(grid, visited, i,j,n,m);
                }
            }
        }
        return ans;
        
    }
};