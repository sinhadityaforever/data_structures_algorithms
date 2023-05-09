class Solution {
public:
    //recursive
    
    
    int solve(int m, int n, string text1, string text2, vector<vector<int>> &dp){
//         if(x<0 || y<0){
//             return 0;
//         }
//         if(dp[x][y]!=-1){
//             return dp[x][y];
//         }
        
//         if(text1[x]==text2[y]){
//             return dp[x][y]= 1+solve(x-1, y-1, text1, text2, dp);
//         }
//         return dp[x][y]=max(solve(x-1, y, text1, text2, dp), solve(x, y-1, text1, text2, dp));
        
        
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(i==0 && text1[0]==text2[j]){
        //             dp[i][j]=1;
        //         }
        //         else if(j==0 && text2[0]==text1[i]){
        //             dp[i][j]=1;
        //         }
        //     }
        // }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        return solve(m, n, text1, text2, dp);
    }
};