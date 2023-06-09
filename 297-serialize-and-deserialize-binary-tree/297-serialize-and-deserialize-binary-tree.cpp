/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        queue<TreeNode*> q;
        string s;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front==NULL){
                s.push_back('#');
                s.push_back(',');
            }
            else{
               s+=to_string(front->val)+',';
                q.push(front->left);
                q.push(front->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.length()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            getline(s, str, ',');
            if(str=="#"){
                front->left=NULL;
            }
            else{
                TreeNode* tmp = new TreeNode(stoi(str));
                front->left=tmp;
                q.push(tmp);
            }
            getline(s, str, ',');
            if(str=="#"){
                front->right=NULL;
            }
            else{
                TreeNode* tmp = new TreeNode(stoi(str));
                front->right=tmp;
                q.push(tmp);
            }
        
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));