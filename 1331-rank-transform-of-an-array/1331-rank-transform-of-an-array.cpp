class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> dummy = arr;
        sort(dummy.begin(), dummy.end());
        int tmp =1;
        for(int i =0; i<n; i++){
            if(mp[dummy[i]]==0){
                mp[dummy[i]]=tmp;
                tmp++;
            }
        }
        
        for(int i=0; i<n; i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};