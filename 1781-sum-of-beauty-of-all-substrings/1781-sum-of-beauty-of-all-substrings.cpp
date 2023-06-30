class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans =0;
        
        for(int i=0; i<n; i++){
            vector<int> v(26, 0);
            for(int j=i; j<n; j++){
                v[s[j]-'a']++;
                int mini = 1e9;
                int maxi=-1;
                for(auto it: v){
                    if(it!=0){
                        mini = min(mini, it);
                        maxi = max(maxi, it);
                    }
                    
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};