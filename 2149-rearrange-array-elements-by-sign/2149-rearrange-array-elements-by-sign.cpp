class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;
        
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                positives.push_back(nums[i]);
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                negatives.push_back(nums[i]);
            }
        }
        
        int i=0; 
        int j =0;
        while(i<positives.size()){
           nums[j]=positives[i];
            i++;
            j=j+2;
       }
        
        i=0;
        j=1;
        while(i<negatives.size()){
           nums[j] = negatives[i];
            i++;
            j=j+2;
        }
        
        return nums;
    }
};