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
    
    
    TreeNode* solve(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart,        int postEnd, unordered_map<int, int> &mp){
        
        if(inStart>inEnd || postStart>postEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = mp[root->val];
        int numsRight = inEnd - inRoot;
        
        root->right = solve(inorder, inRoot+1, inEnd, postorder, postEnd-numsRight-1, postEnd-1, mp);
        root->left = solve(inorder, inStart, inRoot-1, postorder, postStart, postEnd-numsRight-1, mp);
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i =0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        
        int inStart =0;
        int postStart =0;
        int inEnd=inorder.size()-1;
        int postEnd = postorder.size()-1;
        
        return solve(inorder, inStart, inEnd, postorder, postStart, postEnd, mp);
        
        
    }
};