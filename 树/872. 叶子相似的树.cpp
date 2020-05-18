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
    vector<int> numOfLeaves1;
    vector<int> numOfLeaves2;
    void postOrderTraversal(TreeNode* root, vector<int>& numOfLeaves) {
        if(root == NULL) return ;
        postOrderTraversal(root -> left, numOfLeaves);
        postOrderTraversal(root -> right, numOfLeaves);
        if(root -> left == NULL && root -> right == NULL) {
            numOfLeaves.push_back(root -> val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        postOrderTraversal(root1, numOfLeaves1);
        postOrderTraversal(root2, numOfLeaves2);
        if(numOfLeaves1.size() != numOfLeaves2.size()) return false;
        for(int i = 0; i < numOfLeaves1.size(); i++) {
            if(numOfLeaves1[i] != numOfLeaves2[i]) {
                return false;
            }
        }
        return true;
    }
};
