class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        //dist, row, col
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,                   greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,0}});
        
        dist[0][0]=0;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int dis = top.first;
            int row = top.second.first;
            int col = top.second.second;
            if(row==n-1 && col==m-1) return dis;
            int dRow[] = {0,1,0,-1};
            int dCol[] = {1,0,-1,0};
            for(int i=0; i<4; i++){
                int nRow=row+dRow[i];
                int nCol = col + dCol[i];
                
                if(nRow<n && nRow>=0 && nCol<m && nCol>=0){
                    int diff = max(abs(heights[row][col]-heights[nRow][nCol]), dis);
                    if(diff<dist[nRow][nCol]){
                        
                        dist[nRow][nCol]=diff;
                        pq.push({diff, {nRow, nCol}});
                    
                }
            }
        }
    }
        return -1;
    }
    
                                       
    
};