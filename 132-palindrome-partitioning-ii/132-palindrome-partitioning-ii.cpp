class Solution {
public:
    
    
    bool isPalindrome(string &a, int i, int j){
     
        while(i<j){
            if(a[i]!=a[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string s){
//         if(i==n) return 0;
//         if(dp[i]!=-1) return dp[i];
//         int mini = 1e9;
        
//         for(int j= i; j<n; j++){
//             if(isPalindrome(s, i, j)){
//                 int tmpMin = 1+ solve(j+1, s, n, dp);
//                 mini = min(mini, tmpMin);
//             }
//         }
//         return dp[i] = mini;
        int n = s.length();
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i>=0; i--){
            int mini = 1e9;
            for(int j =i; j<n; j++){
                if(isPalindrome(s, i, j)){
                    int tmpMin = 1+ dp[j+1];
                    mini = min(mini, tmpMin);
                }
            }
            dp[i]= mini;
        }
        return dp[0]-1;
    }
    
    int minCut(string s) {
       
        return solve(s);
    }
};