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
    TreeNode* recursionBuildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = 0;
        while(inorder[inStart + rootIndex] != preorder[preStart]) {
            rootIndex++;
        }
        root -> left = recursionBuildTree(preorder, preStart + 1, preStart + rootIndex, inorder, inStart, inStart + rootIndex - 1);
        root -> right = recursionBuildTree(preorder, preStart + rootIndex + 1, preEnd, inorder, inStart + rootIndex + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursionBuildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
