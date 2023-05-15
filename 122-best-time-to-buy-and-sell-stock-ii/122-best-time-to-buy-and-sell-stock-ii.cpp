class Solution {
public:
    
    int solve(vector<int> &prices, int n, vector<vector<int>> &dp){
//         if(index==prices.size()){
//             return 0;
//         }
//         if(dp[index][buy]!=-1){
//             return dp[index][buy];
//         }
//         int op1 = -1e9;
//         int op2=-1e9;
        
//         if(buy==0){
//             //buy option available
//             //1. no transaction
//             op1= solve(prices, index+1, 0, dp);
            
//             //2. transaction
//             op2= -prices[index]+solve(prices, index+1,1, dp);
//         }
//         else{
//             //buy option not available, ie sell available
//             //1. no transaction
//             op1= solve(prices, index+1, 1, dp);
//             op2=prices[index]+solve(prices, index+1, 0, dp);
//         }
//         return dp[index][buy]= max(op1, op2);
            
        
        long profit;
        
        for(int i=n-1; i>=0; i--){
            for(int j=1; j>=0; j--){
                int op1 = -1e9;
                int op2 = -1e9;
                if(j==0){
                    op1 = dp[i+1][0];
                    op2=-prices[i]+dp[i+1][1];
                }
                else{
                    op1=dp[i+1][1];
                    op2=prices[i]+dp[i+1][0];
                }
                dp[i][j]=max(op1, op2);
            }
        }
        return dp[0][0];
        
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        return solve(prices, n, dp);
    }
};