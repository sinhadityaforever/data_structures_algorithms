class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q; // row, col, time
        
        int maxTime =0;
        
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        
        
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,-1,0,1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;
            maxTime = max(time, maxTime);
            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow]                            [ncol]==0){
                   
                    vis[nrow][ncol]=2;
                    q.push({{nrow, ncol}, time+1});
                    
                }
            }
            
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return maxTime;
        
        
        
    }
};