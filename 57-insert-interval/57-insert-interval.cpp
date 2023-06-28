class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int i=0;
        for(auto it: intervals){
            if(!ans.empty() && ans.back()[1]>=it[0]){
                vector<int> tmp;
                tmp.push_back(ans.back()[0]);
                tmp.push_back(max(ans.back()[1], it[1]));
                ans.pop_back();
                ans.push_back(tmp);
            }
            else{
                ans.push_back(it);
            }
        }
        return ans;
    }
};