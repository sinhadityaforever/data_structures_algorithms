class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if(k==0) return nums;
        if(k>=(n+1)/2){
           
            return ans;
        }
        
        int l1 =0;
        int r1=k-1;
        int index=k;
        int l2=k+1;
        int r2=2*k;
        long long lSum=0;
        long long rSum=0;
        
        for(int i=l1; i<=r1; i++){
            lSum+=nums[i];
        }
        for(int i=l2; i<=r2; i++){
            rSum+=nums[i];
        }
        
        vector<int> tmpAns;
        while(r2<n){
            int avg = (lSum+rSum+nums[index])/(2*k+1);
            tmpAns.push_back(avg);
            lSum-=nums[l1];
            l1++;
            r1++;
            lSum+=nums[r1];
            rSum-=nums[l2];
            l2++;
            r2++;
            if(r2<n)
            rSum+=nums[r2];
            index++;
        }
        index=k;
        for(auto it: tmpAns){
            ans[index]=it;
            index++;
        }
        return ans;
    }
};