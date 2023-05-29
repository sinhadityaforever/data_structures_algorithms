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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool ltr = true;
        
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> tmp;
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                tmp.push_back(front->val);
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            if(!ltr){
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
            ltr = !ltr;
        }
        return ans;
    }
};