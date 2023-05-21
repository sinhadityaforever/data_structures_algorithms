class Solution {
public:

    
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] && 1+dp[j]==dp[i]){
                    cnt[i]=cnt[i]+cnt[j];
                }
            }
        }
        
        int ans=0;
        int lcs =1;
        for(int i=0; i<n; i++){
            if(dp[i]>=lcs){
                lcs=dp[i];
            }
        }
        for(int i=0; i<n; i++){
            if(dp[i]==lcs){
                ans+=cnt[i];
            }
        }
        return ans;
        
    }
};