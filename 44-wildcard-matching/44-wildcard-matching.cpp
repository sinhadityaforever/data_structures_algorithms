class Solution {
public:
    
    
    bool solve(int m, int n, string s, string p, vector<vector<int>> &dp){
//         if(i<0 && j<0){
//             return true;
//         }
//         if(j<0 && i>=0){
//             return false;
//         }
//         if(i<0 && j>=0){
//             bool isAllStar=true;
//             for(int k =j; k>=0; k--){
//                 if(p[k]!='*'){
//                     isAllStar=false;
//                 }
//             }
//             return isAllStar;
//         }
        
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
        
        
//         if(s[i]==p[j]){
//             return dp[i][j]= solve(i-1, j-1, s, p, dp);
//         }
//         else{
//             if(p[j]=='?'){
//                 return dp[i][j]= solve(i-1, j-1, s, p, dp);
//             }
//             else if(p[j]=='*'){
//                 return dp[i][j]= solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
//             }
//             else{
//                 return dp[i][j]= false;
//             }
//         }
        dp[0][0]=1;
        for(int i=1; i<=m; i++){
            dp[i][0]=0;
        }
        for(int j=1; j<=n; j++){
            bool allStar=true;
            for(int k =1; k<=j; k++){
                if(p[k-1]!='*'){
                    allStar=false;
                }
            }
            dp[0][j]=allStar;
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    if(p[j-1]=='?'){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*'){
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        
        return dp[m][n];
        
    }
    
    bool isMatch(string s, string p) {
        
        int m = s.length();
        int n = p.length();
      
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, s, p, dp);
    }
};