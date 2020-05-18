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
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        if(root -> left != NULL) {
            root -> left -> val += 10 * (root -> val);
        }
        if(root -> right != NULL) {
            root -> right -> val += 10 * (root -> val);
        }
        if(root -> left == NULL && root -> right == NULL) {
            sum += root -> val;
        }
        sumNumbers(root -> left);
        sumNumbers(root -> right);
        return sum;
    }
};
