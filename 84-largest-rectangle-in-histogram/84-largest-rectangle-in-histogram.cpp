class Solution {
public:
    
    void nextSmall(vector<int> &ans, vector<int> &nums, int n){
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=(st.top()-1);
            }
            st.push(i);
        }
        
        for(int i=0; i<n; i++){
            if(ans[i]==-1){
                ans[i]=n-1;
            }
        }
    }
    
    void prevSmall(vector<int> &ans, vector<int> &nums, int n){
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=(st.top()+1);
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            if(ans[i]==-1){
                ans[i]=0;
            }
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n, -1);
        vector<int> next(n, -1);
        prevSmall(prev, heights, n);
        nextSmall(next, heights, n);
     
        
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            int ht = (next[i]-prev[i]+1)*heights[i];
            maxi=max(ht, maxi);
        }
        return maxi;
    }
};