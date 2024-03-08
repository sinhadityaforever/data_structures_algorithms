class Solution {
public:
    
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto it: nums) mp[it]++;
        
        vector<pair<int, int>> tmp;
        for(auto it: mp){
            tmp.push_back({it.first, it.second});
        }
        sort(tmp.begin(), tmp.end(), cmp);
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(tmp[i].first);
        }
        return ans;
        
        
        
    }
};