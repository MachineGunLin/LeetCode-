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
    vector<vector<int>> res;
    void DFS(TreeNode* root, int sum, vector<int> onePath) {
        if(root == NULL) {
            return ;
        }
        onePath.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL) {
            int currentSum = 0;
            for(auto weight : onePath) {
                currentSum += weight;
            }
            if(currentSum == sum) {
                res.push_back(onePath);
            }
        }
        DFS(root -> left, sum, onePath);
        DFS(root -> right, sum, onePath);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        DFS(root, sum, {});
        return res;
    }
};
