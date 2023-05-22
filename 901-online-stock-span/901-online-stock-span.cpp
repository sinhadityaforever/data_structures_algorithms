class StockSpanner {
public:
    
    vector<int> prices;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int n= prices.size();
        int count=0;
        for(int i=n-1; i>=0; i--){
            if(prices[i]<=price){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */