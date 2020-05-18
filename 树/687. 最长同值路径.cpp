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
    int ans = 0;
    int findMaxPath(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = findMaxPath(root -> left);
        int right = findMaxPath(root -> right);
        if(root -> left == NULL || root -> val != root -> left -> val) {
            left = 0;
        }
        if(root -> right == NULL || root -> val != root -> right -> val) {
            right = 0;
        }
        ans = max(ans, left + right + 1);
        return max(left + 1, right + 1);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        findMaxPath(root);
        return ans - 1;
    }
};
