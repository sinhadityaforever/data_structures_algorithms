class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if(k>=arr.size()) return 0;
        unordered_map<int, int> mp;
        for(auto it: arr) mp[it]++;
        
        vector<int> count;
        for(auto it: mp){
            count.push_back(it.second);
        }
        
        
        
        sort(count.begin(), count.end());
        int n = count.size();
        int i=0;
        while(i<n && k>0){
            if(count[i]==0) i++;
            else{
                k--;
                count[i]--;
            }
            
        }
        
        int ans =0;
        for(auto it: count){
            if(it>0) ans++;
        }
        return ans;
    }
};