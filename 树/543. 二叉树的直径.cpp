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
    int diameter = 0;
    int depth(TreeNode* root) {
        if(root == NULL) return 0;
        int L = depth(root -> left);
        int R = depth(root -> right);
        diameter = max(diameter, L + R + 1);
        return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 1;
        depth(root);
        return diameter - 1;
    }
};
