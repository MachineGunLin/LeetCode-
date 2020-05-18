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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root -> val > val) {
            if(root -> left != NULL) {
                insertIntoBST(root -> left, val);
            } else {
                TreeNode* temp = new TreeNode;
                temp -> val = val;
                temp -> left = temp -> right = NULL;
                root -> left = temp;
            }
        }
        if(root -> val < val) {
            if(root -> right != NULL) {
                insertIntoBST(root -> right, val);
            } else {
                TreeNode* temp = new TreeNode;
                temp -> val = val;
                temp -> left = temp -> right = NULL;
                root -> right = temp;
            }
        }
        return root;
    }
};
