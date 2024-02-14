class Solution {
public:
    
    bool solve(vector<int> arr, int k){
        int n = arr.size();
          vector<vector<int>> dp(n, vector<int>(k+1, 0));
    // return solve(n-1, k, arr, dp);
     for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }

    if(arr[0]<=k){
        dp[0][arr[0]] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            bool notPick = dp[i-1][j];
            bool pick =0;
            if(arr[i]<=j) pick = dp[i-1][j-arr[i]];
            dp[i][j] = pick || notPick;
        }
    }
    return dp[n-1][k];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(auto it: nums) sum+=it;
        if(sum%2==1) return 0;
        return solve(nums, sum/2);
    }
};