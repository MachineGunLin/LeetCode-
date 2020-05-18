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
    vector<TreeNode*> nodes;
    void inOrderTraversal(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inOrderTraversal(root -> left);
        nodes.push_back(root);
        inOrderTraversal(root -> right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        inOrderTraversal(root);
        TreeNode* new_root = nodes[0];
        for(auto node : nodes) {
            node -> left = NULL;
        }
        for(int i = 0; i < nodes.size() - 1; i++) {
            nodes[i] -> right = nodes[i + 1];
        }
        return new_root;
    }
};
