class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        int n = nums.size();
        int curr = n-1;
        int bp = 1e9;
        while(curr!=0){
            int prev = curr-1;
            if(nums[prev]<nums[curr]){
                bp = prev;
                break;
            }
            curr--;
        }
        if(bp==1e9){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=n-1; i>=bp+1; i--){
            if(nums[i]>nums[bp]){ swap(nums[i], nums[bp]);
            break;}
        }
        
        reverse(nums.begin()+bp+1, nums.end());
        return;
        
    }
};