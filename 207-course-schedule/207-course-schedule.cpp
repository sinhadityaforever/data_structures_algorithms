class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<int> adj[numCourses];
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        //Topo sort bfs
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
        
        //final ans
        return topo.size()==numCourses;
    }
};