class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> v(m, vector<int>(n, -1));
        int ans =0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j== 0){
                    v[i][j]=matrix[i][j];
                    ans+=v[i][j];
                    continue;
                }
                if(matrix[i][j]==0){
                    v[i][j]=0;
                    continue;
                }
                int left = v[i][j-1];
                int up = v[i-1][j];
                int upLeft = v[i-1][j-1];
                
                v[i][j]= 1+ min(upLeft, min(up, left));
                ans+=v[i][j];
                
            }
        }
        return ans;
        
    }
};