class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i, j}, 0});
                    vis[i][j]=1;
                }
            }
        }
        
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,-1,0,1};
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int row = top.first.first;
            int col = top.first.second;
            int dist = top.second;
            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==1 && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, dist+1});
                    ans[nrow][ncol]=dist+1;
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
};