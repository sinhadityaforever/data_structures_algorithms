/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    
    vector<int> inorder;
     int pointer =-1;
    
    BSTIterator(TreeNode* root) {
        TreeNode* node = root;
       
        stack<TreeNode*> st;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                TreeNode* top = st.top();
                st.pop();
                inorder.push_back(top->val);
                node=top->right;
            }
        }
    }
    
    int next() {
        pointer++;
        return inorder[pointer];
    }
    
    bool hasNext() {
        if(pointer+1<inorder.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */