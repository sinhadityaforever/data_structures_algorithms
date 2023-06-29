#include<bits/stdc++.h>

class Solution {
public:
    int maxDepth(string s) {
     int ans=0;
    stack<char> st;
        for(auto it: s){
            if(it=='('){
                st.push(it);
                if(st.size()>ans) ans=st.size();
            }
            else if(it==')'){
                st.pop();
            }
        }
        return ans;
    }
};