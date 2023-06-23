class Solution {
public:
    
    bool isValid(string s){
        if(s[0]==')') return false;
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(!st.empty()){
                char top = st.top();
                if(top!='(') return false;
                st.pop();
                }
                else{
                    return false;
                }
               
            }
        }
        return st.empty();
    }
    
    
    void solve(int n, string currAns, vector<string> &ans){
        if(n==0){
            if(isValid(currAns)) ans.push_back(currAns);
            return;
        }
        
        char c[]={'(', ')'};
        for(int i=0; i<2; i++){
            currAns.push_back(c[i]);
            solve(n-1, currAns, ans);
            currAns.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        string currAns;
        vector<string> ans;
        solve(2*n, currAns, ans);
        return ans;
    }
};