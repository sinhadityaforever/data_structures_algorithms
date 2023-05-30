class Solution {
public:
    
    int solve(int index, int k, vector<int> &arr, int n, vector<int> &dp){
        if(index==n) return 0;
        if(dp[index]!=-1) return dp[index];
        int maxSum=-1e9;
        int currMax = -1e9;
        
        for(int i=index; i<min(n, index+k); i++){
            currMax = max(currMax, arr[i]);
            int currSum = (i-index+1)*currMax + solve(i+1, k, arr, n, dp);
            maxSum = max(maxSum, currSum);
        }
        return dp[index] = maxSum;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, arr, n, dp);
    }
};