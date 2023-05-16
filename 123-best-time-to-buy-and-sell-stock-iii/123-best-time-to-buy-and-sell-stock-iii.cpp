class Solution {
public:
    
    
    int solve(vector<int> & prices, int n, vector<vector<vector<int>>> &dp){
//         if(index==prices.size() || allowed==0){
//            return 0;
//         }
//         if(dp[index][buy][allowed]!=-1){
//             return dp[index][buy][allowed];
//         }
        
//         int op1=-1e9;
//         int op2 = -1e9;
        
//         if(buy==0){
//             //can buy
//             //1.do nothing
//             op1=solve(prices, index+1, 0, allowed, dp);
//             //2 buy
//             op2= - prices[index]+solve(prices, index+1, 1, allowed, dp);
//         }
//         else{
//             //can sell
//             //1. dont sell
//             op1 = solve(prices, index+1, 1, allowed, dp);
//             //sell
//             op2= prices[index]+solve(prices, index+1, 0, allowed-1, dp);
//         }
//         return dp[index][buy][allowed] = max(op1, op2);
        
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                dp[n][i][j]=0;
            }
        }
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<2; j++){
                dp[i][j][0]=0;
            }
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int k=1; k<3; k++){
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
        
        return dp[0][0][2];
        
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return solve(prices, n, dp);
    }
};