class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        int i=0;
        int m = haystack.length();
        int n = needle.length();
        
        while(i<m){
            int tmp =i;
            int j = 0;
            while(j<n){
                if(haystack[tmp]==needle[j]){
                    tmp++;
                    j++;
                }
                else{
                    break;
                }
            }
            if(j==n){
                return i;
            }
            else{
                i++;
            }
        }
        return -1;
        
        
    }
};