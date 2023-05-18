class Solution {
public:
    
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> currAns, int n){
        if(n==0){
            ans.push_back(currAns);
            return;
        }
        
    
        for(int i=0; i<n; i++){
            swap(nums[i], nums[n-1]);
            int temp = nums[n-1];
            currAns.push_back(temp);
            nums.pop_back();
            solve(nums, ans, currAns, n-1);
            nums.push_back(temp);
            currAns.pop_back();
            swap(nums[i], nums[n-1]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currAns;
        solve(nums, ans, currAns, nums.size());
        return ans;
    }
};