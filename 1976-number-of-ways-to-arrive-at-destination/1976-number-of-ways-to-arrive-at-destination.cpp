class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n];
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        //time, node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        pq.push({0, 0});
        
        //time, numberOfPaths
        vector<pair<long long, long long>> times(n, {1e18, 0});
        times[0]={0,1};
        int mod = (int)(1e9+7);
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            long long time = top.first;
            int node = top.second;
            
            for(auto it: adj[node]){
                long long nTime = it.second;
                int nNode = it.first;
                
                if(time+nTime<times[nNode].first){
                    times[nNode]={time+nTime, times[node].second};
                    pq.push({time+nTime, nNode});
                }
                else if(time+nTime==times[nNode].first){
                    times[nNode].second = (times[nNode].second+times[node].second)%mod;
                   
                }
            }
        }
        
        return times[n-1].second%mod;
        
    }
};