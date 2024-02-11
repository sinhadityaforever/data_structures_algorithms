class Solution {
public:
    
    
    int solve(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i>1){
                pick+=dp[i-2];
            }
            int notPick = dp[i-1];
            dp[i]= max(pick, notPick);
        }
        return dp[n-1];
       
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> arr1;
        vector<int> arr2;
        for(int i=1; i<n; i++) arr1.push_back(nums[i]);
        for(int i=0; i<n-1; i++) arr2.push_back(nums[i]);
        return max(solve(arr1), solve(arr2));
    }
};