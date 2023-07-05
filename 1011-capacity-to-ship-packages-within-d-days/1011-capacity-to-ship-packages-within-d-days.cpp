class Solution {
public:
    
    bool isPossible(vector<int> &weights, int days, int mid){
        int i=0;
        int tmp = mid;
        while(i<weights.size()){
            if(weights[i]<=tmp){
                tmp-=weights[i];
                i++;
            }
            else{
                tmp = mid;
                days--;
                if(days<=0) return false;
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int s = -1e9;
        int e=0;
        for(auto it: weights){
            s=max(it, s);
            e+=it;
        }
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(weights, days, mid)) e=mid-1;
            else s=mid+1;
            
        }
        return s;
        
    }
};