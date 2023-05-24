class Solution {
public:
    
    //Z matching algorithm
    
    
    vector<int> prepZ(string total){
        
        int n = total.length();
        vector<int> z(n);
        int l=0;
        int r=0;
        for(int i=1; i<n; i++){
            if(i>r){
                l=i;
                r=i;
                while(r<n && total[r]==total[r-l]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
            
            
            else{
                int relIdx = i-l;
                if(i+z[relIdx]<=r){
                    z[i]=z[relIdx];
                }
                else{
                    l=i;
                    while(r<n && total[r]==total[r-l]){
                        r++;
                    }
                    z[i]=r-l;
                    r--;
                }
            }
            
        }
        return z;
    }
    
    int strStr(string haystack, string needle) {
        string total = needle+"$"+haystack;
        int p = needle.length();
        int s = haystack.length();
        int t = total.length();
        vector<int> z = prepZ(total);
      
        
        for(int i=0; i<t; i++){
            if(z[i]==p){
                return i-p-1;
            }
        }
        return -1;
    }
};