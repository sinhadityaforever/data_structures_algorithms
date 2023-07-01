class Solution {
public:
    
    int atMost(vector<int> &nums, int goal){
        int n = nums.size();
        int r=0,l=0,ans=0,sum=0;
        while(r<n){
            sum+=nums[r];
            while(l<=r && sum>goal){
                sum-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums, goal)-atMost(nums, goal-1);
        
    }
};