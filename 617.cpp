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
    void dfs(TreeNode* pleft, int l, TreeNode* left, TreeNode* right){
        if(left==nullptr && right==nullptr) return  ;
        if(left == nullptr){
            if(l==0)
                pleft->left = right;
            else pleft->right = right;
            return ;
        }
        if(right == nullptr){
            return ;
        }
        left->val = left->val + right->val;
        dfs(left, 0, left->left, right->left);
        dfs(left, 1, left->right, right->right);
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr){
            root1=root2;
            return root1;
        }
        else if(root2==nullptr) return root1;

        root1->val = root1->val + root2->val;

        dfs(root1, 0, root1->left, root2->left);
        dfs(root1, 1, root1->right, root2->right);
        return root1;
    }
};
