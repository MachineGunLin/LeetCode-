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
    bool flag = false;
    void DFS(TreeNode* root, int currentSum, int sum) {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) {
            if(currentSum + root -> val == sum) {
                flag = true;
            }
        }
        DFS(root -> left, currentSum + root -> val, sum);
        DFS(root -> right, currentSum + root -> val, sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        DFS(root, 0 , sum);
        if(flag == true) return true;
        else return false;
    }
};
