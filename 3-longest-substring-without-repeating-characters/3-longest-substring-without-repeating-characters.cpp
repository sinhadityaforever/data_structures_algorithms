class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0;
        string S=s;
        unordered_map<char, int> mp;
        
        int l, r=0;
        while(l<S.length() && r<S.length()){
            if(mp.find(S[r])==mp.end()){
                //no repeats
                length = max(length, r-l+1);
                mp[S[r]]++;
                r++;
                
            }
            else{
                //repeats
               
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(S[l]);
                }
                l++;    
            }
        }
        return length;
    }
};