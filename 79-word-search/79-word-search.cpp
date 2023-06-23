class Solution {
public:
    
    
    bool solve(vector<vector<char>> &board, int row, int col, int n, int m, vector<vector<int>> &vis, string word, int index){
        if(index==word.size()) return true;
        if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || board[row][col]!=word[index]) return false;
        vis[row][col]=1;
        int dRow[] = {0,1,0,-1};
        int dCol[]= {1,0,-1,0};
        for(int i=0; i<4; i++){
            bool ans = solve(board, row+dRow[i], col+dCol[i], n, m, vis, word, index+1);
            if(ans) return true;
        }
        vis[row][col]=0;
        return false;
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool ans = solve(board, i, j, n, m, vis, word, 0);
                if(ans) return true;
            }
        }
        return false;
    }
};