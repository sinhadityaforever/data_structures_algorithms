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
    
    
    int findIndex(vector<int> &inorder, int value){
        for(int i =0; i<inorder.size(); i++){
            if(inorder[i]==value) return i; 
        }
        return -1;
    }
    
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd){
        //base
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = findIndex(inorder, preorder[preStart]);
        int inNums = inIndex-inStart;
        root->left = solve(preorder, inorder, preStart+1, preStart+inNums, inStart, inIndex-1);
        root->right = solve(preorder, inorder, preStart+inNums+1, preEnd, inIndex+1, inEnd);
        return root;
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return solve(preorder, inorder, 0, n-1, 0, n-1);
        
    }
};