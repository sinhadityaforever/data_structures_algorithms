class Solution {
public:
    
  int largestRectangleArea(vector < int > & histo) {
    stack < int > st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea =0;
        int m = matrix[0].size();
        vector<int> v(m, 0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    
                    v[j]++;
                }
                else{
                    v[j]=0;
                }
            }
            int tmpAns = largestRectangleArea(v);
          
            maxArea = max(maxArea, tmpAns);
        }
        return maxArea;
    }
};