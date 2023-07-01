class Solution {
public:
    
    int atmost(vector<int> &nums, int k){
        int l=0,r=0,curr=0,ans=0;
        int n = nums.size();
        while(r<n){
            if(nums[r]%2==1) curr++;
            while(l<=r && curr>k){
                if(nums[l]%2==1){
                    curr--;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k)-atmost(nums, k-1);
    }
};