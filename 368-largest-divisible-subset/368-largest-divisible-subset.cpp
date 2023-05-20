class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n, -1);
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            hash[i]=i;
            for(int j =0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    hash[i]=j;
                    dp[i]=1+dp[j];
                }
            }
        }
        
        int ans =0;
        int lastIndex=0;
        
        for(int i=0; i<n; i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastIndex=i;
            }
        }
        
        
        vector<int> subset;
        subset.push_back(nums[lastIndex]);
        while(lastIndex!=hash[lastIndex]){
            
            lastIndex=hash[lastIndex];
            subset.push_back(nums[lastIndex]);
        }
        reverse(subset.begin(), subset.end());
        return subset;
        
    }
};