class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
            
        }
        
        vector<int> minTimes(n+1, 1e9);
        minTimes[k]=0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0,k});
        while(!pq.empty()){
            auto top = pq.top();
            int node = top.second;
            int time = top.first;
            
            pq.pop();
            
            for(auto it: adj[node]){
                int nNode = it.first;
                int nTime = it.second;
                if(minTimes[nNode]>nTime+time){
                    minTimes[nNode]=nTime+time;
                    pq.push({minTimes[nNode], nNode});
                }
                
            }
        }
        int minTime=-1e9;
        for(int i=1; i<=n; i++){
            minTime = max(minTime, minTimes[i]);
        }
        if(minTime==1e9) return -1;
        return minTime;
    }
};