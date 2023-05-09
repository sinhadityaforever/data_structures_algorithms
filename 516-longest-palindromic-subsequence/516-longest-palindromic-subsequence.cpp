class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==s1[j-1]){
                    int val = 1+dp[i-1][j-1];
                    dp[i][j]=val;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
        
    }
};