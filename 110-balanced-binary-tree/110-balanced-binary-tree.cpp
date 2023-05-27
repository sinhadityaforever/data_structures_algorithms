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
    
    int height(TreeNode* root, bool &isTrue){
        if(root==NULL){
            return 0;
        }
        
        int left = height(root->left, isTrue);
        int right = height(root->right, isTrue);
        isTrue = isTrue && abs(left-right)<=1;
        return 1 + max(left, right);
        
    }
    
    bool isBalanced(TreeNode* root) {
        bool isTrue = true;
        height(root, isTrue);
        return isTrue;
    }
};