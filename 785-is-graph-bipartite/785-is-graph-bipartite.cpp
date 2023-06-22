class Solution {
public:
    
    bool bfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &color){
        vis[node]=1;
        color[node]=1;
        queue<pair<int, int>> q;
        q.push({node, color[node]});
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int node = top.first;
            int nodeColor = top.second;
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    int tmp = nodeColor==1 ? 0 : 1;
                    color[it]=tmp;
                    q.push({it, tmp});
                }
                else{
                    if(color[it]==nodeColor) return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>  color(n, -1);
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bool ans = bfs(i, graph, vis, color);
                if(!ans) return false;
            }
        }
        for(auto it: color){
            cout<<it<<endl;
        }
        return true;
    }
};