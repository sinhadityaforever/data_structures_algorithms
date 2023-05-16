class Solution {
public:
    
    int solve(vector<int>& prices, int n, vector<vector<int>> &dp){
//         if(index==n || index==n+1){
//             return 0;
//         }
//         if(dp[index][buy]!=-1){
//             return dp[index][buy];
//         }
        
//         int op1=-1e9;
//         int op2=-1e9;
        
//         if(buy==0){
//             op1 = solve(prices, index+1, n, 0, dp);
//             op2 = -prices[index] + solve(prices, index+1, n, 1, dp);
//         }
//         else{
//             op1= solve(prices, index+1, n, 1, dp);
//             op2 = prices[index] + solve(prices, index+2, n, 0, dp);
//         }
//         return dp[index][buy]= max(op1, op2);
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                int op1 = -1e9;
                int op2 = -1e9;
                if(j==0){
                    op1 = dp[i+1][0];
                    op2 = -prices[i]+dp[i+1][1];
                }
                else{
                    op1 = dp[i+1][1];
                    op2=prices[i]+ dp[i+2][0];
                }
                dp[i][j]=max(op1, op2);
            }
        }
        return dp[0][0];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        return solve(prices, n, dp);
    }
};