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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) {
            return NULL;
        }
        TreeNode* new_root = new TreeNode;
        new_root -> val = nums[nums.size() / 2];
        vector<int> leftChild(nums.begin(), nums.begin() + nums.size() / 2);
        new_root -> left = sortedArrayToBST(leftChild);
        vector<int> rightChild(nums.begin() + nums.size() / 2 + 1, nums.end());
        new_root -> right = sortedArrayToBST(rightChild);
        return new_root;
    }
};
