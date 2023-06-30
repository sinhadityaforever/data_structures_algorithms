class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rmin =0;
        int rmax=matrix.size()-1;
        int cmin =0;
        int cmax = matrix[0].size()-1;
        vector<int> ans;
        while(rmin<=rmax && cmin<=cmax){
            //right
            for(int i=cmin; i<=cmax; i++){
                ans.push_back(matrix[rmin][i]);
            }
            rmin++;
            if(rmin>rmax || cmin > cmax) break;
            //down
            for(int i=rmin; i<=rmax; i++){
                ans.push_back(matrix[i][cmax]);
            }
            cmax--;
            if(rmin>rmax || cmin > cmax) break;
            //left
            for(int i = cmax; i>=cmin; i--){
                ans.push_back(matrix[rmax][i]);
            }
            rmax--;
            if(rmin>rmax || cmin > cmax) break;
            //up
            for(int i=rmax; i>=rmin; i--){
                ans.push_back(matrix[i][cmin]);
                
            }
            cmin++;
            if(rmin>rmax || cmin > cmax) break;
        }
        return ans;
    }
};