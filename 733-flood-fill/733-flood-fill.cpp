class Solution {
public:
    
 
    
    void solve(vector<vector<int>> &image, int m, int n, int row, int col, int color, int srcColor){
        if(row==-1 || row>=m || col==-1 || col>=n){
            return;
        }
        if(image[row][col]!=srcColor) return;
        image[row][col]=color;
        solve(image,m,n,row-1,col,color,srcColor);
        solve(image,m,n,row+1,col,color,srcColor);
        solve(image,m,n,row,col-1,color,srcColor);
        solve(image,m,n,row,col+1,color,srcColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if( image[sr][sc] == color ) return image;
        solve(image,image.size(), image[0].size(), sr,sc, color, image[sr][sc]);
        return image;
    }
};