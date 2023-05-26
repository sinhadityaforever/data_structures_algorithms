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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q; //Node, hd, level
        map<int, map<int, multiset<int>>> mp; //hd, level, value
        
        q.push({root, {0,0}});
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            TreeNode* node = front.first;
            int hd = front.second.first;
            int level = front.second.second;
            
            mp[hd][level].insert(node->val);
            if(node->left){
                q.push({node->left, {hd-1, level+1}});
                
            }
            if(node->right){
                q.push({node->right, {hd+1, level+1}});
            }
            
        }
        
        vector<vector<int>> ans;
        for(auto i: mp){
            vector<int> tmp;
            for(auto j: i.second){
                // tmp.insert(tmp.end(), j.second.begin(), j.second.end());
                for(auto k: j.second){
                    tmp.push_back(k);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
        
    }
};