class Solution {
public:
    
    
    void solve(vector<vector<int>> &ans, vector<int> dw, int target, vector<int> &candidates, int index, int n){
       if(target==0){
           ans.push_back(dw);
       }
        
        
        for(int i=index; i<n; i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            dw.push_back(candidates[i]);
            if(candidates[i]<=target){
                solve(ans, dw, target-candidates[i], candidates, i+1, n);
            }
            
            dw.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> dw;
        sort(candidates.begin(), candidates.end());
        solve(ans, dw, target, candidates, 0, n);
        return ans;
    }
};