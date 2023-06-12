class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> revAdj[v];
        
        for(int i=0; i<v; i++){
            for(auto it: graph[i]){
                revAdj[it].push_back(i);
            }
        }
        
        vector<int> inDegree(v, 0);
        for(int i=0; i<v; i++){
            for(auto it: revAdj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        
        //push all ele with indegree 0 (from reversed graph), or outdegree 0 (from original             graph)
        
        for(int i=0; i<v; i++){
            if(graph[i].size()==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            topo.push_back(top);
            for(auto it: revAdj[top]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
        
    }
};