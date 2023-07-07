class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if(k<arr[0]) return k;
        
        k-=(arr[0]-1);
        
        for(int i=0; i<n-1; i++){
            int diff = arr[i+1]-arr[i];
            if(diff-1<k) k-=(diff-1);
            else{
                return arr[i]+k;
            }
        }
        return arr[n-1]+k;
    }
};