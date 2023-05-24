class Solution {
public:
    
    //Z matching algorithm
    int strStr(string haystack, string needle) {
        string s;
        s=needle+'$'+haystack;
        int m = haystack.length();
        int n = needle.length();
        int o = s.length();
        vector<int> z;
        z.push_back(0);
        int i =1;
        while(i<o){
            int maxLen=0;
            int tmp=i;
            int j=0;
            while(j<o){
               if(s[tmp]==s[j]){
                maxLen++;
                j++;
                tmp++;
            } 
            else{
               z.push_back(maxLen);
                break;
            }
            }
            
            i++;
            
        }
        
        // for(int i=0; i<z.size(); i++){
        //     cout<<i<<": "<<z[i]<<endl;
        // }
        // cout<<"n: "<<n<<endl;
        
        for(int j=0; j<o; j++){
            if(z[j]==n){
                return j-n-1;
            }
        }
        return -1;
    }
};