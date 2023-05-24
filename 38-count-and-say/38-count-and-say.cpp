class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        
        string prev = countAndSay(n-1);
        int i=0;
        string ans;
        while(i<prev.length()){
            int currNum = prev[i]-'0';
            int freq=1;
            int j=i+1;
            while(j<prev.length()){
                if(prev[j]==prev[i]){
                    freq++;
                    j++;
                }
                else{
                    break;
                }
                
            }
           ans+=to_string(freq);
            ans+=to_string(currNum);
            i=j;
        }
        return ans;
    }
};