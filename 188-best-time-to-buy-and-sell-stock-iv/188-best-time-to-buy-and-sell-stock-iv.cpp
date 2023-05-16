class Solution {
public:
    
    int solve(vector<int>& prices, int m, int n){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(m+1, 0)));
        
         for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int k=1; k<=m; k++){
                    int op1 = -1e9;
                    int op2 = -1e9;
                    
                    if(j==0){
                        op1 = dp[i+1][0][k];
                        op2 = -prices[i]+dp[i+1][1][k];
                    }
                    else{
                        op1=dp[i+1][1][k];
                        op2=prices[i] + dp[i+1][0][k-1];
                    }
                    dp[i][j][k]=max(op1, op2);
                }
            }
        }
        
        return dp[0][0][m];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices, k, prices.size());
    }
};