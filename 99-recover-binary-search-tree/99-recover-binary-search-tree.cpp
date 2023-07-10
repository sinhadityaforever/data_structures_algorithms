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
class Solution {
public:
    
    void calcIn(TreeNode* root, vector<int> &inorder){
        if(root==NULL) return;
        calcIn(root->left, inorder);
        inorder.push_back(root->val);
        calcIn(root->right, inorder);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        calcIn(root, inorder);
        vector<int> sorted = inorder;
        sort(sorted.begin(), sorted.end());
        int val1, val2;
        for(int i=0; i<sorted.size(); i++){
            if(sorted[i]!=inorder[i]){
                val1 = sorted[i];
                val2 = inorder[i];
                break;
            }
        }
        
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top->val ==val1){
                top->val = val2;
            }
            else if(top->val == val2){
                top->val = val1;
            }
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        
    }
};