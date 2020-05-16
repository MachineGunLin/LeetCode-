/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 
class Solution {
public:
    int getGoodNodes(TreeNode* root, int currentMax) {
        if(root == NULL) {
            return 0;
        }
        int res = 0;
        if(root -> val >= currentMax) {
            currentMax = root -> val;
            res = 1;
        }
        res += getGoodNodes(root -> left, currentMax) + getGoodNodes(root -> right, currentMax);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return getGoodNodes(root, -10001);
    }
};
