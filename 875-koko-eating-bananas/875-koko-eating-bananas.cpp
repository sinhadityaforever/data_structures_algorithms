class Solution {
public:
    
    bool isPossible(vector<int> &piles, int h, int mid){
 
        int i=0;
        while(i<piles.size()){
            if(piles[i]<=mid) h--;
            else{
                if(piles[i]%mid==0) h-=(piles[i]/mid);
                else{
                    h=h-(piles[i]/mid)-1;
                }
            
            }
            if(h<0) return false;
            i++;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int s = 1;
        int e = piles[n-1];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(piles, h, mid)) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};