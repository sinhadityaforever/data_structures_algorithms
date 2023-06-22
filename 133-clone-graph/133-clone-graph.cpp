/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        vector<int> visited(101, 0);
        vector<Node*>  nodes(101);
        for(int i =0; i<101; i++){
            nodes[i]= new Node();
        }
        
        queue<Node*> q;
        q.push(node);
        bool start =0;
        unordered_set<int> adj[101];
        Node* clone = new Node();
        while(!q.empty()){
            queue<Node*> dq = q;
            Node* top = q.front();
            visited[top->val]=1;
            int originalVal = top->val;
            q.pop(); 
            nodes[originalVal]->val = originalVal;
            if(start==0){
                clone = nodes[originalVal];
                start=1;
            }
            
            for(auto it: top->neighbors){
                adj[top->val].insert(it->val);
               if(!visited[it->val]){
                    q.push(it);
                   
               }
                
            }
        }
        
        for(int i=0; i<101; i++){
            if(adj[i].size()>0){
                for(auto it: adj[i]){
                    nodes[i]->neighbors.push_back(nodes[it]);
                }
                
            }
        }
        
        return clone;
        
    }
};