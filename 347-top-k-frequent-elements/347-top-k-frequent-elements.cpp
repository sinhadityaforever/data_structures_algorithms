class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1. sort
        sort(nums.begin(), nums.end());
        //2. create freq array;
        vector<int> freq;
        int currCount =1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                currCount++;
            }
            else{
                freq.push_back(currCount);
                currCount=1;
            }
        }
        freq.push_back(currCount);
        
        //3. Create prefix sum array
        int sum =0;
        vector<int> prefix;
        for(int i=0; i<freq.size(); i++){
            sum+=freq[i];
            prefix.push_back(sum);
        }
        
        //4. Main Logic
        vector<int> ans;
        while(k>0){
            int maxIndex = 0;
            for(int i=0; i<freq.size(); i++){
                if(freq[maxIndex]<freq[i]){
                    maxIndex=i;
                }
            }
            if(maxIndex==0){
                ans.push_back(nums[0]);
            
            }
            else{
                ans.push_back(nums[prefix[maxIndex-1]]);
            }
            k--;
            freq[maxIndex]=-1;
        }
        return ans;
    }
};