class Solution {
public:
    
    
    int solve(vector<int>& nums, int index, int prev, vector<vector<int>> &dp){
        if(index<0){
            return 0;
        }
        if(dp[index][prev]!=-1){
            return dp[index][prev];
        }
        //notTake
        int notTake = solve(nums, index-1, prev, dp);
        
        int take = -1e9;
        if(nums[index]<nums[prev]){
            
            take = 1+ solve(nums, index-1, index, dp);
        }
        return dp[index][prev] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(1e9);
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, n-1, n, dp);
    }
};