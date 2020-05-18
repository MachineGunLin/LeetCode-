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
    vector<int> res;
    void postOrder(TreeNode* root) {
        if(root == NULL) return ;
        postOrder(root -> left);
        postOrder(root -> right);
        res.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return res;
    }
};
