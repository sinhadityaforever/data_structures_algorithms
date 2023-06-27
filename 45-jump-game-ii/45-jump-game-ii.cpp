class Solution {
public:
    
    int solve(vector<int> &nums, int index, int n, vector<int> &dp){
        if(index>=n-1) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans = 1e9;
        for(int i=1; i<=nums[index]; i++){
            int tmp = 1+ solve(nums, index+i, n, dp);
            ans = min(tmp, ans);
        }
        return dp[index]= ans;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, n, dp);
    }
};