class Solution {
public:
    
    int solve(int prevC, int x, int y, int z, vector<vector<vector<vector<int>>>> &dp){
        if((prevC!=1 && y<=0) || (prevC!=2 && x<=0 && z<=0) || (x<=0 && y<=0 && z<=0)) return 0;
        if(dp[prevC][x][y][z]!=-1) return dp[prevC][x][y][z];
        
        int aa= 0;
        int bb=0;
        int ab =0;
        
        if(prevC!=1){
            if(y>0)
            bb= 2 + solve(1, x, y-1, z, dp);
        }
        if(prevC!=2){
        if(x>0)
           aa=2+solve(2, x-1, y, z, dp);
        if(z>0)
            ab = 2+solve(1, x, y, z-1, dp);
        }
        return dp[prevC][x][y][z] = max({aa,bb,ab});
        
    }
    
    int longestString(int x, int y, int z) {
        vector<vector<vector<vector<int>>>> dp(3, vector<vector<vector<int>>>(x+1, vector<vector<int>>(y+1, vector<int>(z+1, -1))));
        return solve(0, x, y, z, dp);
    }
};