class Solution {
public:
    
    void bfs(int node, vector<int> &vis, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it: adj[front]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        vector<int> adj[n];
        
        //created adj list from matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    if(isConnected[i][j]){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }
        
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                bfs(i, vis, adj);
            }
        }
        return ans;
    }
};