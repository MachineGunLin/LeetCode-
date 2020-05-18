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
    TreeNode* recursionBuildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if(inStart > inEnd || postStart > postEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIndex = 0;
        while(inorder[inStart + rootIndex] != postorder[postEnd]) {
            rootIndex++;
        }
        root -> left = recursionBuildTree(inorder, inStart, inStart + rootIndex - 1, postorder, postStart, postStart + rootIndex - 1);
        root -> right = recursionBuildTree(inorder, inStart + rootIndex + 1, inEnd, postorder, postStart + rootIndex, postEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recursionBuildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
