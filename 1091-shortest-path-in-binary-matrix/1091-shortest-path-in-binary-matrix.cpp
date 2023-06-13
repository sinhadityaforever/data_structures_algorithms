class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0]=0;
        //dist, {row, col}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0,0}});
        
        while(!q.empty()){
            auto top = q.front();
            int dis = top.first;
            int row = top.second.first;
            int col = top.second.second;
            q.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nRow = row+i;
                    int nCol = col+j;
                    
                    if(nRow<n && nRow>=0 && nCol<m && nCol>=0 && grid[nRow][nCol]==0){
                        if(dist[nRow][nCol]>dist[row][col]+1){
                            dist[nRow][nCol]=dist[row][col]+1;
                            q.push({dist[nRow][nCol], {nRow, nCol}});
                        }
                    }
                    
                }
            }
        }
        
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1]+1;
        
    }
};