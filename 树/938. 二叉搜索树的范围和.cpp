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
    int sum;
    void inOrderTraversal(TreeNode* root, int L, int R) {
        if(root == NULL) return ;
        inOrderTraversal(root -> left, L, R);
        if(root -> val >= L && root -> val <= R) sum += root -> val;
        inOrderTraversal(root -> right, L, R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        inOrderTraversal(root, L, R);
        return sum;
    }
};
