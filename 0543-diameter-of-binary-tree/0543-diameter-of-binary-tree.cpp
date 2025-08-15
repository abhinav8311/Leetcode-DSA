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
    int result;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return result;
    }

    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lh = dfs(root->left);
        int rh = dfs(root->right);

        result = max(result, lh+rh);

        return 1+max(lh,rh);
    }
};