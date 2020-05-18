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
    int res = int(1e9);
    vector<int> nodeNum;
    void inOrderTraversal(TreeNode* root) {
        if(root == NULL) return ;
        inOrderTraversal(root -> left);
        nodeNum.push_back(root -> val);
        inOrderTraversal(root -> right);
    }
    int getMinimumDifference(TreeNode* root) {
        inOrderTraversal(root);
        for(vector<int>::iterator it = nodeNum.begin(); it != nodeNum.end(); it++) {
            if(it == nodeNum.end() - 1) continue;
            else {
                if(*(it + 1) - *it < res) {
                    res = *(it + 1) - *it;
                }
            }
        }
        return res;
    }
};
