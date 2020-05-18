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
    vector<int> nodes;
    void inOrderTraversal(TreeNode* root) {
        if(root == NULL) {
            return ;
        }
        inOrderTraversal(root -> left);
        nodes.push_back(root -> val);
        inOrderTraversal(root -> right);
    }
    int kthLargest(TreeNode* root, int k) {
        inOrderTraversal(root);
        reverse(nodes.begin(), nodes.end());
        return nodes[k - 1];
    }
};
