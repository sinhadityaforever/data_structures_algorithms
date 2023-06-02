class MedianFinder {
public:
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top()>num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        
        //size comp
        if(maxHeap.size()>minHeap.size()+1){
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        else if(maxHeap.size()<minHeap.size()){
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()) return ((double)maxHeap.top()+(double)minHeap.top())/2;
        else return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */