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
    bool isValid(TreeNode* root, long lval, long rval) {
        if(root == NULL) {
            return true;
        }
        if(root -> val <= lval || root -> val >= rval) {
            return false;
        }
        return isValid(root -> left, lval, root -> val) && isValid(root -> right, root -> val, rval);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
