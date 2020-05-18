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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(root -> left == NULL && root -> right == NULL) return true;
        if(abs(getHeight(root -> left) - getHeight(root -> right)) > 1) return false;
        if(isBalanced(root -> left) == false) return false;
        if(isBalanced(root -> right) == false) return false;
        return true;
    }
    int getHeight(TreeNode* root) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return 1;
        return max(getHeight(root -> left), getHeight(root -> right)) + 1;
    }
};
