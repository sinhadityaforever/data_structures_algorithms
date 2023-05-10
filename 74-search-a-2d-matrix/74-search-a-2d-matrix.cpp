class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> v;
        // for(auto i: matrix){
        //     for(auto j: i){
        //         v.push_back(j);
        //     }
        // }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                v.push_back(matrix[i][j]);
            }
        }
        
        int s =0;
        int e = m*n-1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(target==v[mid]){
                return true;
            }
            else if(target<v[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return false;
        
         
    }
};