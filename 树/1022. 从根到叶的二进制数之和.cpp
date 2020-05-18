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
    int mod = 1e9 + 7;
    void preOrderTraversal(TreeNode* root, int currentSum) {
        if(root == NULL) {
            return ;
        }
        currentSum = 2 * currentSum + root -> val;
        if(root -> left == NULL && root -> right == NULL) {
            sum += currentSum;
            sum %= mod;
        }
        preOrderTraversal(root -> left, currentSum);
        preOrderTraversal(root -> right, currentSum);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        preOrderTraversal(root, 0);
        return sum;
    }
};
