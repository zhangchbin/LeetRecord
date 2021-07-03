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
    int ans = 0;
    int dfs(TreeNode*cur){
        if(cur==nullptr) return 0;
        int ldis = dfs(cur->left) + 1;
        int rdis = dfs(cur->right) + 1;
        this->ans = max(this->ans, ldis + rdis - 1);
        return max(ldis, rdis);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max(this->ans-1, 0);
    }
};
