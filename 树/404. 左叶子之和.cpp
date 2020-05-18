/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        DFS(root);
        return sum;
    }
    void DFS(TreeNode* root) {
        if(root == NULL) return ;
        if(root -> left == NULL && root -> right == NULL) return ;
        if(root -> left != NULL && root -> left -> left == NULL && root -> left -> right == NULL) {
            sum += root -> left -> val;
        }
        DFS(root -> left);
        DFS(root -> right);
    }
};
