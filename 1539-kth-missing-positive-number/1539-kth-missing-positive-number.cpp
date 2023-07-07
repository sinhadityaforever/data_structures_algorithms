class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
       vector<int> missing;
        for(int i=0; i<n; i++){
            missing.push_back(arr[i]-(i+1));
        }
        
        int s =0;
        int e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(missing[mid]<k){
                s=mid+1;
            }
            else e= mid-1;
        }
        if(e<0) return k;
        return arr[e]+ (k-missing[e]);
        
    }
};