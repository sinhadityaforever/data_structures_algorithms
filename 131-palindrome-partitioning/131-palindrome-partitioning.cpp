class Solution {
public:
    
    bool isPalindrome(int i, int j, string s){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    
    void solve(string s, int i, vector<vector<string>> &ans, vector<string> currAns, int n){
        if(i==n){
            
            ans.push_back(currAns);
            return;
        };
        
        for(int j=i; j<n; j++){
            if(isPalindrome(i,j,s)){
                
                string tmp;
                for(int k =i; k<=j; k++){
                    tmp.push_back(s[k]);
                    // if(i==n-1 && j==n-1 && k==i) cout<<k;
                }
                currAns.push_back(tmp);
                
                solve(s, j+1, ans, currAns, n);
                currAns.pop_back();
            }
        }
        
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currAns;
        solve(s, 0, ans, currAns, s.length());
        return ans;
    }
};