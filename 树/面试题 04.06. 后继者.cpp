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
            return ;
        }
        inOrderTraversal(root -> left);
        nodes.push_back(root);
        inOrderTraversal(root -> right);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL) {
            return NULL;
        }
        inOrderTraversal(root);
        for(int i = 0; i < nodes.size() - 1; i++) {
            if(nodes[i] -> val == p -> val) {
                return nodes[i + 1];
            }
        }
        return NULL;
    }
};
