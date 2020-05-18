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
    void inOrderTraversal(TreeNode* root) {
        if(root == NULL) {
            return ;
        }
        inOrderTraversal(root -> left);
        res.push_back(root -> val);
        inOrderTraversal(root -> right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) {
            return res;
        }
        inOrderTraversal(root1);
        inOrderTraversal(root2);
        sort(res.begin(), res.end());
        return res;
    }
};
