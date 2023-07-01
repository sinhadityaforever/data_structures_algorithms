class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> prefix;
        int currSum=0;
        int ans=0;
        for(auto it: nums){
            currSum+=it;
            if(currSum==goal) ans++;
            if(prefix.find(currSum-goal)!=prefix.end()){
                ans+=prefix[currSum-goal];
            }
            prefix[currSum]++;
        }
        
        return ans;
        
    }
};