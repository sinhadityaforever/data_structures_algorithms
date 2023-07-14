class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int ans =1;
        for(auto it: arr){
            if(mp.find(it-difference)==mp.end()){
                mp[it]=1;
            }
            else mp[it] = mp[it-difference]+1;
            ans = max(ans, mp[it]);
        }
        return ans;
    }
};