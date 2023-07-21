class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int ele;
        int count=0;
        for(auto it: nums){
            if(count==0){
                ele = it;
                count++;
            }
            else if(it == ele) count++;
            else count--;
        }
        int freq=0;
        for(auto it: nums){
            if(it==ele) freq++;
        }
        if(freq<=n/2) return -1;
        
        int currCount=0;
        int firstSubarraylen=0;
        for(int i=0; i<n-1; i++){
            firstSubarraylen++;
            if(nums[i]==ele){
                currCount++;
            }
            if(2*currCount>(i+1) && 2*(freq-currCount)>(n-i-1)){
                return i;
            }
        }
        return -1;
    }
};