class Solution {
public:
    
    
    void solve(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> currAns){
        if(target==0){
            ans.push_back(currAns);
            return;
        }
        if(index<0){
            return;
        }
        
        //notTake
        solve(candidates, target, index-1, ans, currAns);
        
        //Take
        if(candidates[index]<=target){
         currAns.push_back(candidates[index]);
        solve(candidates, target-candidates[index], index, ans, currAns);
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currAns;
        solve(candidates, target, candidates.size()-1, ans, currAns);
        return ans;
    }
};