class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans=0;
        int curr=0;
        for(auto it: nums){
            if(it%2==1) curr++;
            if(curr==k) ans++;
            if(mp.find(curr-k)!=mp.end()){
                ans+=mp[curr-k];
            }
            mp[curr]++;
            
        }
        return ans;
    }
};