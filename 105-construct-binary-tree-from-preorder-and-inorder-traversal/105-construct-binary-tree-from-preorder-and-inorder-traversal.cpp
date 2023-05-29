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
    
   
    
    TreeNode* solve(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart,        int inEnd, unordered_map<int, int> &mp){
       
        if(inStart>inEnd || preStart > preEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = solve(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
        root->right = solve(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int inStart=0;
        int inEnd = inorder.size()-1;
        int preStart = 0;
        int preEnd = preorder.size()-1;
        for(int i =0; i<=inEnd; i++){
            mp[inorder[i]] = i;
        }
        
        return solve(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
        
        
    }
};