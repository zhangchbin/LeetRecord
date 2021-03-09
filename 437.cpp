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
    int target;
    int ans = 0;
    map<TreeNode*, int>ma;

    vector<TreeNode*>tree;
    
    void build(TreeNode*cur, int sum){
        ma[cur] = sum;
        if(cur->left != NULL){
            build(cur->left, sum + cur->left->val);
        }
        if(cur->right != NULL){
            build(cur->right, sum + cur->right->val);
        }
        
    }

    void dfs(TreeNode*cur){
        for(int i = 0; i < tree.size(); i++){
            if(ma[cur] - ma[tree[i]] + tree[i]->val == target) ans++;
        }
        if(cur->val == target) ans++;
        tree.push_back(cur);
        if(cur->left != NULL) dfs(cur->left);
        if(cur->right != NULL) dfs(cur->right);
        tree.pop_back();
    }


    int pathSum(TreeNode* root, int sum) {
        target = sum; 
        if(root == NULL) return 0;
        build(root, root->val);
        dfs(root);
        return ans;
    }
};
