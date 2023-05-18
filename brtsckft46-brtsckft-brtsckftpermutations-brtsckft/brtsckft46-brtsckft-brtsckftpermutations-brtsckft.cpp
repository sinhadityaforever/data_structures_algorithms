class Solution {
public:
    
    void solve(vector<int> &nums, vector<vector<int>> &ans, int n){
        if(n==0){
            ans.push_back(nums);
            return;
        }
        
    
        for(int i=0; i<n; i++){
            swap(nums[i], nums[n-1]);
            solve(nums, ans, n-1);
            swap(nums[i], nums[n-1]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currAns;
        solve(nums, ans, nums.size());
        return ans;
    }
};