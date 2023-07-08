class Solution {
public:
    
    bool isPossible(vector<int> &nums, int k, int mid){
       
        int currSum=0;
        for(int i=0; i<nums.size(); i++){
           currSum+=nums[i];
            if(currSum>mid){
                k--;
                currSum=nums[i];
            }
            
        }
        
        return k>0;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int s=-1e9;
        int e =0;
        for(auto it: nums){
            s=max(s, it);
            e+=it;
        }
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(nums, k, mid)) e= mid-1;
            else s = mid+1;
            
        }
        return s;
    }
};