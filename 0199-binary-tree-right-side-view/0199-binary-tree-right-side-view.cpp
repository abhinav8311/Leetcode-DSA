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
    vector<int> res;
public:
    vector<int> rightSideView(TreeNode* root) {
        rightTree(root,0);

        return res;
    }

    void rightTree(TreeNode* root, int level){
        if(root == NULL){
            return;
        }

        if(level == res.size()){
            res.push_back(root->val);
        }

        rightTree(root->right,level+1);
        rightTree(root->left,level+1);
    }
};