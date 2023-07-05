class Solution {
public:
    
    int isPossible(vector<int> &arr, int m, int k, int mid){
      cout<<mid<<endl;
        int tmpM=m;
        int tmpK=k;
        for(int i=0; i<arr.size(); i++){
            if(tmpM==0) return true;
            if(arr[i]>mid){
                tmpK=k;
            }
            else{
                if(tmpK>0){
                    tmpK--;
                    if(tmpK==0){
                      
                        tmpM--;
                        tmpK=k;
                    }
                }
            }
        }
        cout<<tmpM<<endl;
        return tmpM==0;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(bloomDay.size()<m*k) return -1;
        int n = bloomDay.size();
       int s =1e9;
        int e = -1e9;
        for(auto it: bloomDay){
            s=min(s, it);
            e=max(e, it);
        }
        int maxi =e;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(bloomDay, m, k, mid)){
                
                e=mid-1;
            }
            else s=mid+1;
        }
        if(s>maxi || s<0) return -1;
        return s;
    }
};