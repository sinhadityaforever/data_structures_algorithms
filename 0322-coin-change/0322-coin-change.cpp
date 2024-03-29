class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i=1; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
            else
            dp[0][i] = 1e9;
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<=amount; j++){
                int notPick = dp[i-1][j];
                int pick = 1e9;
                if(j>=coins[i]){
                    pick = 1+dp[i][j-coins[i]];
                }
                dp[i][j] = min(pick, notPick);
            }
        }
        
        return dp[n-1][amount]>=1e9 ? -1 : dp[n-1][amount];
        
    }
};