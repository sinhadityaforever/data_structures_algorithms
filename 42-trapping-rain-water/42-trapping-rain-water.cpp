class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax(n);
        vector<int> sufMax(n);
        int currMax=0;
        for(int i=0; i<n; i++){
            if(height[i]>currMax){
                currMax= max(currMax, height[i]);
                preMax[i]=currMax;
            }
            else{
                preMax[i]=currMax;
            }
            
        }
        
        currMax=0;
        for(int i=n-1; i>=0; i--){
            if(height[i]>currMax){
               currMax= max(currMax, height[i]);
                sufMax[i]=currMax;
            }
            else{
                sufMax[i]=currMax;
            }
            
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=(min(preMax[i], sufMax[i])-height[i]);
        }
        return ans;
        
    }
};