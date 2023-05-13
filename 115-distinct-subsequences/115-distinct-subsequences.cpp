class Solution {
public:
    
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        //explore
        if(s[i]==t[j]){
            return dp[i][j]= solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
        }
        else{
            return dp[i][j]=solve(i-1, j, s, t, dp);
        }
        
    }
    
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, s, t, dp);
    }
};