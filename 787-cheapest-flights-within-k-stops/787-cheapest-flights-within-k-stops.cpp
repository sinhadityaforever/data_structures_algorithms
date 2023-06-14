class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        
        //Adj list
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
            
        }
        
        
        queue<pair<pair<int, int>,int>> q;
        
        q.push({{0, 0}, src});
        vector<int> prices(n, 1e9);
        prices[src]=0;
        
        while(!q.empty()){
            auto top = q.front();
            int price = top.first.first;
            int kVal = top.first.second;
            int node = top.second;
            q.pop();
            
            
            if(kVal>k+1) continue;
            for(auto it: adj[node]){
                if(kVal<=k && it.second+price<prices[it.first]){
                    prices[it.first]=it.second+price;
                    q.push({{it.second+price, kVal+1}, it.first});
                }
            }
            
        }
        // prices[src]=1e9;
        if(prices[dst]==1e9) return -1;
        return prices[dst];
        
        
        
    }
};