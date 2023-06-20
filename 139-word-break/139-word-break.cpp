class Solution {
public:
    
    

    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        for(auto it: wordDict){
            mp[it]++;
        }
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n]=1;
        
    for(int i=n-1; i>=0; i--){
        string word;
        for(int j =i; j<n; j++){
            word+=s[j];
            if(mp.find(word)!=mp.end()){
                bool ans = dp[j+1];
                if(ans) dp[i]=1;
            }
        }
    }
    
        return dp[0];
    }
};