class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        //prod1 stores max , prod 2 stores min(or, negative max)
        int prod1 = nums[0];
        int prod2 = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            //max
            int tmp = max({nums[i], prod1*nums[i], prod2*nums[i]});
            //min (max negative)
            prod2 = min({nums[i], prod1*nums[i], prod2*nums[i]});
            
            prod1 = tmp;
            res = max(prod1, res);
        }
        return res;
    }
};