class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //finding break point
        int bp = 1e9;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                bp=i;
                break;
            }
        }
        if(bp==1e9){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=nums.size()-1; i>=bp+1; i--){
            if(nums[i]>nums[bp]){
                swap(nums[i], nums[bp]);
                break;
            }
        }

        sort(nums.begin()+bp+1, nums.end());

    }
};