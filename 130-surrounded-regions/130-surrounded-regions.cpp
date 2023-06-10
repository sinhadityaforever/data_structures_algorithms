class Solution {
public:
    
    
    void rec(vector<vector<char>> &board, vector<vector<int>> &vis, int row, int col, int n, int m){
        if(row>=n || row<0 || col>=m || col<0) return;
        if(vis[row][col] || board[row][col]!='O') return;
        
        vis[row][col]=1;
        
        
        vector<int> dRow = {0,-1,0,1};
        vector<int> dCol = {-1,0,1,0};
        for(int i=0; i<4; i++){
            rec(board, vis, row+dRow[i], col+dCol[i], n, m);
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(i==0 || j==0 || i==n-1 || j==m-1){
                     
                    if(board[i][j]=='O'){
                        rec(board, vis, i, j, n,m);
                    }
                }
            }
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};