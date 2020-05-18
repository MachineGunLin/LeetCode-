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
    void invertTree(TreeNode* root) {
        if(root == NULL) {
            return ;
        }
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
    }
    TreeNode* mirrorTree(TreeNode* root) {
        invertTree(root);
        return root;
    }
};
