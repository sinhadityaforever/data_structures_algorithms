class Solution {
public:
    
    //Tabulation
    
//     int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
//         if(i>j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int maxi = -1e9;
//         for(int index=i; index<=j; index++){
//             int ans = nums[i-1]*nums[index]*nums[j+1]
//                         +solve(i, index-1, nums, dp) + solve(index+1, j, nums, dp);
//             maxi = max(ans, maxi);
//         }
//         return dp[i][j] = maxi;
//     }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
//         return solve(1, n, nums, dp);
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int i =n; i>=1; i--){
            for(int j = 1; j<=n; j++){
                if(i>j) continue;
                int maxi = -1e9;
                for(int index = i; index<=j; index++){
                    int ans = nums[i-1]*nums[index]*nums[j+1] + dp[i][index-1] + dp[index+1][j];
                    maxi = max(maxi, ans);
                }
                dp[i][j]=maxi;
            }
        }
        
        return dp[1][n];
        
    }
};