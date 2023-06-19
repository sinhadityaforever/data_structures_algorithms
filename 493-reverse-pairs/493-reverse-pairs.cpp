class Solution {
public:
    
    int merge(int s, int mid, int e, vector<int> &nums){
        int cnt=0;
        vector<int> first;
        vector<int> second;
        for(int i=s; i<=mid; i++){
            first.push_back(nums[i]);
        }
        for(int i = mid+1; i<=e; i++){
            second.push_back(nums[i]);
        }
        
        int firstIndex=0;
        int secondIndex=0;
        int len1 = first.size();
        int len2 = second.size();
        int mainIndex=s;
        while(firstIndex<len1 && secondIndex<len2){
            if(first[firstIndex]<=second[secondIndex]){
                nums[mainIndex++]=first[firstIndex++];
            }
            else{
                nums[mainIndex++]=second[secondIndex++];
                
            }
        }
        
        while(firstIndex<len1){
            nums[mainIndex++]=first[firstIndex++];
            
        }
        while(secondIndex<len2){
            nums[mainIndex++]=second[secondIndex++];
        }
        return cnt;
        
    }
    
    int cntPairs(vector<int> &nums, int s, int e, int mid){
        int count=0;
        int right = mid+1;
        for(int i=s; i<=mid; i++){
            while(right<=e && (long long)nums[i]>2*(long long)nums[right]) right++;
            
                count+=right-(mid+1);
            
        }
        return count;
    }
    
    int mergeSort(int s, int e, vector<int> &nums){
        if(s>=e) return 0;
        int mid = s+(e-s)/2;
        int cnt =0;
        cnt +=mergeSort(s, mid, nums);
        cnt+=mergeSort(mid+1, e, nums);
        cnt+=cntPairs(nums, s,e, mid);
        cnt+=merge(s,mid,e, nums);
        
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size()-1, nums);
    }
};