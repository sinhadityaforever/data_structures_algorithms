class Solution {
public:
    
    int solve(int n, int index, vector<int> &nums, int prev, vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        
        //notTake
        int notTake = solve(n, index+1, nums, prev, dp);
        
        //take
        int take = -1e9;
        if(prev==-1 || nums[index]>nums[prev]){
            take = 1+solve(n, index+1, nums, index, dp);
        }
        return dp[index][prev+1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n, 0, nums, -1, dp);
    }
};