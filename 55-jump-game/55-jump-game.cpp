class Solution {
public:
    
    
    bool solve(vector<int>& nums, int index, int n, vector<int> &dp){
        if(index>=n-1) return true;
        if(dp[index]!=-1) return dp[index];
        for(int i =nums[index]; i>=1; i--){
            bool ans = solve(nums, index+i, n, dp);
            if(ans) return dp[index]= true;
        }
        return dp[index]= false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, n, dp);
        
    }
};