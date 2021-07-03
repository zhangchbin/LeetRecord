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

    TreeNode* dfs(TreeNode*p){
        if(p == nullptr) return nullptr;
        TreeNode* tmp = p->right;
        p->right = dfs(p->left);
        p->left = dfs(tmp);
        return p;
    }

    TreeNode* invertTree(TreeNode* root) {
        root=dfs(root);
        return root;
    }
};
