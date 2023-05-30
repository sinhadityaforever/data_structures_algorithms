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
        vector<int> dp(n+1, 0);
        // return solve(0, k, arr, n, dp);
        
        for(int i = n-1; i>=0; i--){
            int maxSum = -1e9;
            int currMax = -1e9;
            for(int j = i; j<min(n, i+k); j++){
                currMax = max(currMax, arr[j]);
                int currSum = (j-i+1)*currMax + dp[j+1];
                maxSum = max(maxSum, currSum);
            }
            dp[i]= maxSum;
        }
        return dp[0];
    }
};