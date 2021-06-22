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
    int ans = 1;
    void dfs(TreeNode* l, TreeNode* r){
        if(!ans) return ;
        if(l->val != r->val) ans = 0;
        if(l->left !=nullptr && r->right !=nullptr) dfs(l->left, r->right);
        else if(l->left == nullptr && r->right == nullptr) ;
        else ans = 0;
        if(l->right !=nullptr && r->left !=nullptr) dfs(l->right, r->left);
        else if(l->right == nullptr && r->left == nullptr) ;
        else ans=0;
    }
    bool isSymmetric(TreeNode* root) {
        if(root != nullptr) {
            if(root->left == nullptr && root->right == nullptr) ans = 1;
            else if(root->left==nullptr && root->right != nullptr) ans=0;
            else if(root->left!=nullptr && root->right == nullptr) ans=0;
            else dfs(root->left, root->right);
        }
        return ans;
    }
};
