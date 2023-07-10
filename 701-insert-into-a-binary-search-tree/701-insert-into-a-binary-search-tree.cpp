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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root==NULL) return newNode;
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        
        while(curr!=NULL){
            prev= curr;
            if(curr->val>val){
                curr=curr->left;
            }
            else curr=curr->right;
        }
        if(val<prev->val) prev->left = newNode;
        else prev->right = newNode;
        return root;
    }
};