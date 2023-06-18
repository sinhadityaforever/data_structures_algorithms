class Solution {
    
    
    
    
    
public:
    
    int timer =1;
    
    void dfs(vector<int> adj[], vector<int> &vis, vector<int> &low, vector<int> &tin, int parent, int node, vector<vector<int>> &bridges){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(adj, vis, low, tin, node, it, bridges);
                low[node]=min(low[node], low[it]);
                
            
            if(low[it]>tin[node])
                //bridge
                bridges.push_back({it, node});
            }
            else{
                low[node]=min(low[node], low[it]);
            }
    }
        
        
        
        }

    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> vis(n, 0);
        vector<vector<int>> bridges;
        
        dfs(adj, vis, low, tin, -1, 0, bridges);
        return bridges;
        
    }
};