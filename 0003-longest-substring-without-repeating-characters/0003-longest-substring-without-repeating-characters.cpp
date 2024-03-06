class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans =0;
        int l =0;
        unordered_map<char, int> mp;
        for(int r=0; r<s.size(); r++){
            if(mp.find(s[r])!=mp.end()){
                while(l<r && mp.find(s[r])!=mp.end()){
                    mp[s[l]]--;
                    if(mp[s[l]]<=0) mp.erase(s[l]);
                    l++;
                }
            }
            
            mp[s[r]]++;
            ans = max(ans, r-l+1);
            
        }
        return ans;
    }
};