class Solution {
public:
    
    string solve(string a, string b){
        int m = a.length();
        int n = b.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        string ans;
        int i = m;
        int j=n;
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                ans.push_back(a[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    ans.push_back(a[i-1]);
                    i--;
                }
                else{
                    ans.push_back(b[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            ans.push_back(a[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(b[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        return solve(str1, str2);
        
    }
};