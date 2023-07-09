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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, unordered_set<int>> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top->left){
                mp[top->val].insert(top->left->val);
                mp[top->left->val].insert(top->val);
                q.push(top->left);
            }
            if(top->right){
                mp[top->val].insert(top->right->val);
                mp[top->right->val].insert(top->val);
                q.push(top->right);
            }
        }
       
        
        queue<int> q2;
        q2.push(target->val);
        unordered_map<int, int> dist;
        dist[target->val]=0;
        vector<int> ans;
        while(!q2.empty()){
            int top = q2.front();
            q2.pop();
            int distance = dist[top];
            if(distance==k) ans.push_back(top);
            for(auto it: mp[top]){
                if(dist.find(it)==dist.end()){
                    dist[it]=distance+1;
                    q2.push(it);
                }
            }
            
        }
        return ans;
        
    }
};