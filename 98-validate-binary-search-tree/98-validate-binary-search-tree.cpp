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
    
    bool solve(TreeNode* root, long long minRange, long long maxRange){
        if(root==NULL) return true;
        
        bool ans1 = false;
        if(root->val>minRange && root->val<maxRange) ans1=true;
        bool ans2= solve(root->left, minRange, root->val);
        bool ans3 = solve(root->right, root->val, maxRange);
        return ans1 && ans2 && ans3;
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right == NULL) return true;
        return solve(root, -1000000000000, 1000000000000);
    }
};