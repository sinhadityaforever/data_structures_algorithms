class Solution {
public:
    
    int lcs(string a, string b){
        int m = a.length();
        int n = b.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        int l = lcs(word1, word2);
        int l1 = word1.length();
        int l2 = word2.length();
        return (l1+l2)-2*l;
    }
};