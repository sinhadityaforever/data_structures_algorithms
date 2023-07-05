class Solution {
public:
    
    bool isPossible(vector<int>&nums, int mid, int threshold){
        
        for(auto it: nums){
            threshold-=ceil((double)it/(double)mid);
           
            if(threshold<0) return false;
        }
        return threshold>=0;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int s=1;
        int e = nums[0];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(nums, mid, threshold)) e=mid-1;
            else s= mid+1;
        }
        return s;
        
    }
};