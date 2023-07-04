class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s =0;
        int e = n-1;
        
        int mid = s+(e-s)/2;
        
        while(s<=e){
            if(nums[mid]==target || nums[s]==target || nums[e]==target){
                return true;
            }
            if(nums[mid]==nums[s] && nums[s]==nums[e]){
                s++;
                e--;
                continue;
            }
            if(nums[s]<=nums[mid]){
                
                if(nums[s]<=target && target <=nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
                
            }
            mid=s+(e-s)/2;
        }
        return false;
    }
};