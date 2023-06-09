class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth =0;
    KthLargest(int k, vector<int>& nums) {
        // if(nums.size()==0) return;
        kth=k;
        for(int i=0; i<k; i++){
            if(i<nums.size())
                pq.push(nums[i]);
        }
        for(int i=k; i<nums.size(); i++){
            if(i<nums.size()){
             int top = pq.top();
            if(nums[i]>top){
                pq.pop();
                pq.push(nums[i]);
            }   
            }
            
        }
    }
    
    int add(int val) {
        
        int top;
        if(pq.size()==kth){
            top = pq.top();
            if(val>top){
            pq.pop();
            pq.push(val);
            return pq.top();
        }
        else{
            return top;
        }
        }
        else{
            pq.push(val);
            return pq.top();
        }
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */