/*
因为是二叉搜索树，所以中序遍历可以得到一个升序序列。

因此可以中序遍历这个二叉搜索树，把结果存在一个数组中，然后遍历这个数组，计算相邻值的最小值，这个最小值就是答案。
*/

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
    vector<int> nodes;

    void inOrder(TreeNode* root) {
        if(root == NULL) {
            return ;
        }
        inOrder(root -> left);
        nodes.push_back(root -> val);
        inOrder(root -> right);
    }

    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        inOrder(root);
        int res = INT_MAX;
        for(int i = 0; i < nodes.size() - 1; ++i) {
            res = min(res, nodes[i + 1] - nodes[i]);
        }
        return res;
    }
};
