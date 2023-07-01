class Solution {
public:
    
    int atmost(string s, int k){
        int l=0, r=0, ans=0;
        unordered_map<char, int> mp;
        int n = s.size();
        for(r=0; r<n; r++){
            mp[s[r]]++;
            while(l<=r && mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    
    int numberOfSubstrings(string s) {
        return atmost(s,3)-atmost(s,2);
    }
};