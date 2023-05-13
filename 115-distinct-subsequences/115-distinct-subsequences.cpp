class Solution {
public:
    
    int solve(int m, int n, string s, string t){
//         if(j<0){
//             return 1;
//         }
//         if(i<0){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
        
//         //explore
//         if(s[i]==t[j]){
//             return dp[i][j]= solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
//         }
//         else{
//             return dp[i][j]=solve(i-1, j, s, t, dp);
//         }
        
        vector<vector<double>> dp(m+1, vector<double>(n+1));
        
        
        for(int j =0; j<=n; j++){
            dp[0][j]=0;
        }
        for(int i=0; i<=m; i++){
            dp[i][0]=1;
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[m][n];
        
    }
    
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, s, t);
    }
};