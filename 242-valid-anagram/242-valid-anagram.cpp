class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(auto i: s){
            mp[i]++;
        }
        for(auto i: t){
            if(mp.find(i)==mp.end()){
                return false;
            }
            else{
                mp[i]--;
                if(mp[i]==0){
                    mp.erase(i);
                }
            }
        }
        
        if(mp.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};