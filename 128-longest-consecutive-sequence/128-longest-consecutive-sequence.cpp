class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //soln1
        unordered_map<int, int> mp;
        int maxStreak=0;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto i: mp){
            if(mp.find(i.first-1)==mp.end()){
                //potential starting element
                int currStreak=0;
                int currEle=i.first;
                // for(auto j: mp){
                //     if(mp.find(j.first+1)!=mp.end()){
                //         currStreak++;
                //         currEle++;
                //     }
                // }
                while(mp.find(currEle)!=mp.end()){
                    currStreak++;
                    currEle++;
                }
                maxStreak = max(maxStreak, currStreak);
            }
        }
        return maxStreak;
        
        
    }
};