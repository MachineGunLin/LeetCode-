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
    TreeNode* maximumBinaryTree(vector<int>::iterator begin, vector<int>::iterator end) {
        if(begin == end) {
            return NULL;
        }
        auto it = max_element(begin, end);
        TreeNode* root = new TreeNode(*it);
        root -> left = maximumBinaryTree(begin, it);
        root -> right = maximumBinaryTree(it + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return maximumBinaryTree(nums.begin(), nums.end());
    }
};
