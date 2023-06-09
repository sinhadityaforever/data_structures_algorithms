class Solution {
public:
    
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
       if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j]= 1+solve(i-1, j-1, s, t, dp);
        
        return dp[i][j]=max(solve(i-1, j, s,t,dp), solve(i, j-1, s,t, dp));
        
    }
    
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int ans = solve(m-1, n-1, s,t,dp);
        if(ans==s.length()){
            return true;
            
        }
        return false;
    }
};