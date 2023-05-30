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
    
    
   bool solve(TreeNode* left, TreeNode* right){
       if(!left && !right) return true;
       if((!left && right) || (!right && left)) return false;
       
       bool ans1=false;
       bool ans2=false;
       bool ans3=false;
       
       if(left->val == right->val) ans1=true;
       ans2 = solve(left->left, right->right);
       ans3 = solve(left->right, right->left);
       
       return ans1 && ans2 && ans3;
   }
    
    bool isSymmetric(TreeNode* root) {
       if(root == NULL || (!root->left && !root->right)) return true; 
        return solve(root->left, root->right);
    }
};