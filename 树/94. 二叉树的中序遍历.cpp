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
    vector<int> res = {};
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return res;
    }
    void inOrder(TreeNode* root) {
        if(root == NULL) return ;
        inOrder(root -> left);
        res.push_back(root -> val);
        inOrder(root -> right);
    }
};
