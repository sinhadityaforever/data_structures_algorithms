class Solution {
public:
    
    
    bool check(unordered_map<int, int> &mp, int sum){
        if(sum==20){
            
            if(mp[10]>=1 && mp[5]>=1){
                mp[10]--;
                mp[5]--;
                return true;
            }
            else if(mp[5]>=3){
                mp[5]-=3;
                return true;
            }
            
        }
        else if(sum==10){
            if(mp[5]>=1){
                mp[5]--;
                mp[10]++;
                return true;
            }
        }
        else if(sum==5){
            mp[5]++;
            return true;
        }
        return false;
    }
    
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        
        for(auto it: bills){
            bool ans = check(mp, it);
            if(!ans) return false;
        }
        return true;
    }
};