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
        vector<vector<int>> result;//stores each levels as vectors, therefore vector of vectors
        
        if(root==NULL){
            return result;//if no root, resturn result
        }

        queue<TreeNode*>q;//queue to store nodes at 1st
        q.push(root);
        while(!q.empty()){//till queue is not empty
            int n=q.size();//stores size of the queue currently, so that the inner loop traverses through each node of that level
            vector<int>level;//to store that particular level nodes

            for(int i=0;i<n;i++){//iterate till all nodes are traversed in that level
                TreeNode* node=q.front();//store the node to perform operation but pop it later
                q.pop();

                if(node->left) q.push(node->left);//if left of it present, push in queue
                if(node->right) q.push(node->right);//if right of it present, push in queue

                level.push_back(node->val);//finally push the stored node in level
            }
            result.push_back(level);//push that level in result
        }
        return result;
    }
};