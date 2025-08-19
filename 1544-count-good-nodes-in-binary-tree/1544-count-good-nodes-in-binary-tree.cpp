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
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        return countNode(root , root->val);
    }

    int countNode(TreeNode* root, int maxVal){
        if(root == NULL){
            return 0;
        }

        int count = 0;

        if(root->val >= maxVal){
            count++;
            maxVal = root->val;
        }

        count+= countNode(root->left,maxVal);
        count+= countNode(root->right,maxVal);

        return count;
    }
};