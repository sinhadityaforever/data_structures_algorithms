class Solution {
public:
    
    int solve(int index, vector<int> &nums, int target, int n, vector<int> &dp){
        if(index==n-1) return 0;
        if(index>=n) return -1;
        if(dp[index]!=-1) return dp[index];
        int ans = INT_MIN;
        for(int i=index+1; i<n; i++){
            if(abs(nums[index]-nums[i])<=target){
                int tmp = 1+ solve(i, nums, target, n, dp);
                ans = max(tmp, ans);
            }
        }
        return dp[index]= ans;
        
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(0, nums, target, n, dp);
        if(ans<=0) return -1;
        return ans;
    }
};