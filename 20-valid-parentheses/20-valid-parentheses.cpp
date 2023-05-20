class Solution {
public:
    bool isValid(string s) {
         stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]== '['){
                st.push(s[i]);
            }
            if(s[i]==')'){
                if(st.empty()){
                    return false;
                }
                char tmp = st.top();
                
                if(tmp=='('){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(st.empty()){
                    return false;
                }
                char tmp = st.top();
                if(tmp=='{'){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(st.empty()){
                    return false;
                }
                char tmp = st.top();
                if(tmp=='['){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
          
        }
        
        return st.empty();
    }
};