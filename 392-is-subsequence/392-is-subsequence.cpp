class Solution {
public:
    
    bool solve(string s, string t, int i, int j){
        if(j<0 && i>=0) return 0;
        else if(i<0) return 1;
        
        if(s[i]==t[j]){
            return solve(s, t, i-1, j-1);
        }
       
            return solve(s, t, i, j-1);
        
    }
    
    bool isSubsequence(string s, string t) {
        return solve(s,t,s.length()-1, t.length()-1);
    }
};