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
    vector<int> numOfNodes;
    void inOrderTraversal(TreeNode* root) {
        if(root == NULL) return ;
        inOrderTraversal(root -> left);
        numOfNodes.push_back(root -> val);
        inOrderTraversal(root -> right);
    }
    bool findTarget(TreeNode* root, int k) {
        inOrderTraversal(root);
        for(int i = 0; i < numOfNodes.size() - 1; i++) {
            for(int j = i + 1; j < numOfNodes.size(); j++) {
                if(numOfNodes[i] + numOfNodes[j] == k) {
                    return true;
                }
            }
        }
        return false;
    }
};
