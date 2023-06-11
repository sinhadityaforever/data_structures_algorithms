class Solution {
public:
    
    
    bool solve(int node, vector<vector<int>> &graph, vector<int> &color, bool prevColor){
        if(color[node]!=-1){
            if(color[node]==prevColor) return false;
            else return true;
        }
        
        color[node] = !prevColor;
        
        for(auto it: graph[node]){
            bool ans = solve(it, graph, color, !prevColor);
            if(!ans) return false;
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
       int v = graph.size();
        vector<int> color(v, -1);
        for(int i=0; i<v; i++){
            if(color[i]==-1){
                bool ans = solve(i, graph, color, 0);
                if(!ans) return false;
            }
        }
        return true;
        
    }
};