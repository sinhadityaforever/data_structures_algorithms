class Solution {
public:
    
    void solve(vector<vector<int>> &ans, vector<int> ds, int index, vector<int> &nums, int n){
        ans.push_back(ds);
        
        
        for(int i = index; i<n; i++){
            if(i!=index && nums[i-1]==nums[i]){
               continue;
            }
             ds.push_back(nums[i]);
                solve(ans, ds, i+1, nums, n);
                ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(ans, ds, 0, nums, n);
        return ans;
    }
};