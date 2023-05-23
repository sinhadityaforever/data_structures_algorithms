class Solution {
public:
    void reverseStr(string &s, int i, int j){
        while(i<=j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    
    void sanitize(string &s){
        int i=0;
        while(i<s.length()){
            if(s[0]==' '){
                s.erase(0,1);
            }
            if(s[s.length()-1]==' '){
                s.erase(s.length()-1,1);
            }
            if(i!=0 && s[i]==' ' && s[i-1] ==' '){
                s.erase(i-1, 1);
            }
            else{
                i++;
            }
        }
    }
    
    string reverseWords(string s) {
        //recursive
        //1. check if  no space
        
        sanitize(s);
        int n = s.length();
        int i=0;
        int j =n-1;
        while(i<=j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        s.push_back(' ');
        i=0;
        int len=0;
        while(i<n+1){
            if(s[i]==' '){
                reverseStr(s, i-len, i-1);
                len=0;
            }
            else{
               len++; 
            }
            i++;
        }
        s.erase(n);
        
        return s;
        
    }
};