class Solution {
public:
    
    bool compare(string s1, string s2){
        if(s1.length()-1!=s2.length()) return false;
        int i=0;
        int j=0;
        while(i<s1.length()){
            if(j<s2.length() && s2[j]==s1[i]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()) return true;
        return false;
    }
    
 static bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n=words.size();
        vector<int> dp(n, 1);
        
        for(int i=0; i<n; i++){
            for(int j =0; j<i; j++){
                if(compare(words[i], words[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
        }
        
        int ans =1;
        for(int i=0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};