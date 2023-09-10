class Solution {
public:
    int dp[102][102][102]; 
    int solve(int i, int j, int left, vector<int> &boxes){
        if(i > j) return 0;
        if(i == j) return (1+left)*(1+left);
        if(dp[i][j][left] != -1) return dp[i][j][left];
        int cnt = 1;
        int k = i;
        while(boxes[k] == boxes[k+1] && k < j){ cnt++; k++;}
        int del = (cnt+left)*(cnt+left) + solve(k+1, j, 0, boxes);
        int save = 0;
        for(int l = k+1; l <= j; l++){
            if(boxes[l] == boxes[k]){
                save = max(save, solve(k+1, l-1, 0, boxes) + solve(l, j, cnt+left, boxes));
            }
        }
        return dp[i][j][left] = max(save, del);
    }
    int removeBoxes(vector<int>& boxes) {
        //  major point to note here is that subproblem are not independent to each other 
        int n = boxes.size();
        if(n == 1)return 1;
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, 0, boxes);
    }
};