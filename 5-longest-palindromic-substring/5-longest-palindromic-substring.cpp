class Solution {
public:
    
    int expandFromMid(string &s, int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            r++;
            l--;
        }
        return r-l-1;
    }
    
    string longestPalindrome(string s) {
        int st=0;
        int e=0;
        int n = s.length();
        for(int i=0; i<n; i++){
            int l1 = expandFromMid(s, i, i);
            int l2 = expandFromMid(s, i, i+1);
            int l = max(l1, l2);
            if(l>e-st){
                st=i-(l-1)/2;
                e=i+l/2;
            }
        }
        return s.substr(st, e-st+1);
    }
};