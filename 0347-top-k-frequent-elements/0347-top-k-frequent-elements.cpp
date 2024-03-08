class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it: nums) mp[it]++;
        
        vector<int> count[n];
        for(auto it: mp){
            count[it.second-1].push_back(it.first);
        }
        
        vector<int> ans;
        reverse(count, count+n);
        for(int i=0; i<n; i++){
                 if(count[i].size()>0){
                for(auto it: count[i]){
                    if(ans.size()>=k) break;
                    ans.push_back(it);
                }
            }
        }
        // for(int i=n-1; i>n-k-1; i--){
        //     if(count[i].size()>0){
        //         for(auto it: count[i]){
        //             ans.push_back(it);
        //         }
        //     }
        // }
        return ans;
        
    }
};