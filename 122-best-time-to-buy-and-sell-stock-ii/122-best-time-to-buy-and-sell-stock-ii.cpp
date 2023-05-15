class Solution {
public:
    
    int solve(vector<int> &prices, int index, bool buy, vector<vector<int>> &dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int op1 = -1e9;
        int op2=-1e9;
        
        if(buy==0){
            //buy option available
            //1. no transaction
            op1= solve(prices, index+1, 0, dp);
            
            //2. transaction
            op2= -prices[index]+solve(prices, index+1,1, dp);
        }
        else{
            //buy option not available, ie sell available
            //1. no transaction
            op1= solve(prices, index+1, 1, dp);
            op2=prices[index]+solve(prices, index+1, 0, dp);
        }
        return dp[index][buy]= max(op1, op2);
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 0, dp);
    }
};