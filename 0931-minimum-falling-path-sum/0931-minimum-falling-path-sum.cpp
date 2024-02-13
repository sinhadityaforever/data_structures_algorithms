class Solution {
public:
    
    
//     int solve(vector<vector<int>> & matrix, vector<vector<int>> &dp){

        
        
   
        
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
             vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++) dp[0][i] = matrix[0][i];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = dp[i-1][j];
                int upLeft = 1e9;
                int upRight = 1e9;
                if(j>0) upLeft = dp[i-1][j-1];
                if(j<n-1) upRight = dp[i-1][j+1];
                
                dp[i][j] = matrix[i][j] + min(up, min(upLeft, upRight));
            }
        }
        
        int ans =1e9;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};