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
    set<int> s;
    void preOrderTraversal(TreeNode* root) {
        if(root == NULL) return ;
        s.insert(root -> val);
        preOrderTraversal(root -> left);
        preOrderTraversal(root -> right);
    }
    bool isUnivalTree(TreeNode* root) {
        preOrderTraversal(root);
        if(s.size() == 1) return true;
        else return false;
    }
};
