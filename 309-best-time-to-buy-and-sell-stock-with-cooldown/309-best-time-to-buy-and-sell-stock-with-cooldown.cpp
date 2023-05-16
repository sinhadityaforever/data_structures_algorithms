class Solution {
public:
    
    int solve(vector<int>& prices, int index, int n, int buy, vector<vector<int>> &dp){
        if(index==n || index==n+1){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        int op1=-1e9;
        int op2=-1e9;
        
        if(buy==0){
            op1 = solve(prices, index+1, n, 0, dp);
            op2 = -prices[index] + solve(prices, index+1, n, 1, dp);
        }
        else{
            op1= solve(prices, index+1, n, 1, dp);
            op2 = prices[index] + solve(prices, index+2, n, 0, dp);
        }
        return dp[index][buy]= max(op1, op2);
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, n, 0, dp);
    }
};