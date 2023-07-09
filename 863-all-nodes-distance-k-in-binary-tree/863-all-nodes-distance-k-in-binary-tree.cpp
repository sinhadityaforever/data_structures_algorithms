/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void makeParent(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &parentMap){
        if(root==NULL) return;
        parentMap[root]= parent;
        makeParent(root->left, root, parentMap);
        makeParent(root->right, root, parentMap);
    }
    
    
    void solve(TreeNode* root, int k, vector<int> &ans, TreeNode* prev, unordered_map<TreeNode*, TreeNode*> &parentMap){
        if(root==NULL) return;
        if(k==0) ans.push_back(root->val);
        if(root->left && root->left !=prev) solve(root->left, k-1, ans, root, parentMap);
        if(root->right && root->right !=prev) solve(root->right, k-1, ans, root, parentMap);
        if(parentMap[root] && parentMap[root]!=prev) solve(parentMap[root], k-1, ans, root, parentMap);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        makeParent(root, NULL, parentMap); 
        vector<int> ans;
        solve(target, k, ans, NULL, parentMap);
        return ans;
    }
};