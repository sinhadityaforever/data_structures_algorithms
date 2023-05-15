class Solution {
public:
    
    int solve(int m, int n, string word1, string word2, vector<vector<int>> &dp){
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         //insert
        
//         if(word1[i]==word2[j]){
//             return dp[i][j]= solve(i-1, j-1, word1, word2, dp);
//         }
        
//         int insert = 1e9;
//         int replace = 1e9;
//         int deleted = 1e9;
        
//         insert =  1+solve(i-1, j, word1, word2, dp);
//         replace = 1+solve(i-1, j-1, word1, word2, dp);
//         deleted = 1+solve(i, j-1, word1, word2, dp);
        
//         return dp[i][j]=min(insert,min(replace, deleted));
        
//         //min of insert, delete, replace
        
        for(int i=0; i<=m; i++){
            dp[i][0]=i;
        }
        for(int j=0; j<=n; j++){
            dp[0][j]=j;
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]= 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
        
        
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // int ans = solve(m-1,n-1,word1,word2, dp);
        // if(ans>=1e9){
        //     return 0;
        // }
        // return ans;
        return solve(m,n,word1,word2,dp);
    }
};