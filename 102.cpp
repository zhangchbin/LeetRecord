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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        q.push(pair<TreeNode*,int>{root, 1});
        while(!q.empty()){
            pair<TreeNode*, int> mem = q.front();
            q.pop();
            if(mem.second > ans.size()) {vector<int>tmp; ans.push_back(tmp);}
            ans[mem.second-1].push_back(mem.first->val);

            if(mem.first->left!=nullptr) q.push(pair<TreeNode*,int>{mem.first->left, mem.second+1});
            if(mem.first->right!=nullptr) q.push(pair<TreeNode*,int>{mem.first->right, mem.second+1});
        }
        return ans;
    }
};
