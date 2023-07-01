class Solution {
public:
    
    int atmost(vector<int>& nums, int k){
        int l=0, r=0, ans=0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(r=0; r<n; r++){
            mp[nums[r]]++;
            while(l<=r && mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            ans+=r-l+1;
            
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k)-atmost(nums, k-1);
    }
};