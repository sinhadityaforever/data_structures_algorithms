class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int ub = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        int lb = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        if(lb==n || nums[lb]!=target){
            return {-1, -1};
        }
        return {lb, ub-1};
    }
};