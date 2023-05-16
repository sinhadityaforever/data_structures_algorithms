class Solution {
public:
    
    
    int solve(vector<int> & prices, int index, bool buy, int allowed, vector<vector<vector<int>>> &dp){
        if(index==prices.size() || allowed==0){
           return 0;
        }
        if(dp[index][buy][allowed]!=-1){
            return dp[index][buy][allowed];
        }
        
        int op1=-1e9;
        int op2 = -1e9;
        
        if(buy==0){
            //can buy
            //1.do nothing
            op1=solve(prices, index+1, 0, allowed, dp);
            //2 buy
            op2= - prices[index]+solve(prices, index+1, 1, allowed, dp);
        }
        else{
            //can sell
            //1. dont sell
            op1 = solve(prices, index+1, 1, allowed, dp);
            //sell
            op2= prices[index]+solve(prices, index+1, 0, allowed-1, dp);
        }
        return dp[index][buy][allowed] = max(op1, op2);
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return solve(prices, 0, 0, 2, dp);
    }
};