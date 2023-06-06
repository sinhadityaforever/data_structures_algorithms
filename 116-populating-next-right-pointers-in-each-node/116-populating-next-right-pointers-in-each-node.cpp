/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL || root->left==NULL && root->right==NULL) return root;
        vector<Node*> v;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* top = q.front();
                q.pop();
                v.push_back(top);
                if(top->left) q.push(top->left);
                if(top-> right) q.push(top->right);
            }
            v.push_back(NULL);
            
            
        }
        
        for(int i=0; i<v.size(); i++){
             if(v[i]!=NULL){
                 v[i]->next=v[i+1];
             }
        }
        return root;
    }
};