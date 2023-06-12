class Solution {
public:
    
    void topo(int node, vector<int> adj[], vector<int> &visited, stack<int> &st){
        if(visited[node]) return;
        visited[node]=1;
        for(auto it: adj[node]){
            topo(it, adj, visited, st);
        }
        st.push(node);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //find adj list
        vector<int> adj[numCourses];
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        //find topo sort (dfs)
       vector<int> inDegree(numCourses, 0);
        queue<int> q;
        vector<int> topo;
        for(int i=0; i<numCourses; i++){
            for(auto it: adj[i]){
                inDegree[it]++;
            }
        }
        
        for(int i=0; i<inDegree.size(); i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            topo.push_back(top);
            for(auto it: adj[top]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()!=numCourses) return {};
        return topo;
    }
};