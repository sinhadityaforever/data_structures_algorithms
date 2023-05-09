class Solution {
public:

    vector<int> nthRow(vector<int> &prevRow){
        vector<int> ans;
        ans.push_back(1);
        for(int i=0; i<prevRow.size()-1; i++){
            ans.push_back(prevRow[i]+prevRow[i+1]);
        }
        ans.push_back(1);
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);

        for(int i=0; i<numRows-1; i++){
            vector<int> row = nthRow(ans[ans.size()-1]);
            ans.push_back(row);
        }
        return ans;
    }
};