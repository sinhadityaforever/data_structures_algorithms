class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxi=0;
        vector<pair<int, int>> ranges;
        
        for(int i=0;  i<n; i++){
            ranges.push_back({nums[i], nums[i]+2*k});
            if(i==n-1) maxi = nums[i]+2*k;
        }
        
        
        vector<int> overlap(maxi+2, 0);
        for(int i=0; i<n; i++){
            int start = ranges[i].first;
            int end = ranges[i].second;
            overlap[start]++;
            overlap[end+1]--;
        }
        int cnt =0;
        int ans =0;
        for(auto it: overlap){
            cnt+=it;
            ans = max(cnt, ans);
        }
        return ans;
        
        
    }
};