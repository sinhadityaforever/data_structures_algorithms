class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        
        int i=0;
        int j = n-1;
        vector<int> ans;
        while(i<j){
            int sum = v[i].first+v[j].first;
            if(sum==target){
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                break;
            }
            if(sum<target) i++;
            else if(sum>target) j--;
            
        }
        return ans;
        
    }
};