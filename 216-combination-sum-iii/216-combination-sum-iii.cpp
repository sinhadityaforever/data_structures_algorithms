class Solution {
public:
    
    void solve(int k, int n, int number, vector<int> currAns, vector<vector<int>> &ans){
        if(k==0){
            if(n==0) ans.push_back(currAns);
            return;
        }
        if(number>9) return;
        
        solve(k, n, number+1, currAns, ans);
        
        
            currAns.push_back(number);
           
            solve(k-1, n-number, number+1, currAns, ans);
            
            currAns.pop_back();
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vis(10, 0);
        vector<int> currAns;
        vector<vector<int>> ans;
        solve(k, n, 1, currAns, ans);
        return ans;
    }
};