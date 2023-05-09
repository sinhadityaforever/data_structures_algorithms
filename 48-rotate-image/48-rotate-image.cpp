class Solution {
public:
    //brute force
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n, -1));
        
        int rCount=n-1;
        int cCount=0;
        
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                ans[i][j]=matrix[rCount][cCount];
                cCount++;
                
            }
            rCount--;
            cCount=0;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j]=ans[i][j];
            }
        }
        
    }
};