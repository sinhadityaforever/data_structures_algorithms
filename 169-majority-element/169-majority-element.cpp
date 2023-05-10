class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //Moore's voting algorithm
        int element;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                element = nums[i];
            }
            if(element == nums[i]){
                count++;
            }
            else{
                count--;
            }
            
            
        }
        return element;
    }
};