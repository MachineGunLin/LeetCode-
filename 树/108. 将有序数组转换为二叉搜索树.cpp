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
        if(nums.size() == 0) return NULL;
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left_child, right_child;
        for(int i = 0; i < mid; i++) {
            left_child.push_back(nums[i]);
        }
        for(int i = mid + 1; i < nums.size(); i++) {
            right_child.push_back(nums[i]);
        }
        root -> left = sortedArrayToBST(left_child);
        root -> right = sortedArrayToBST(right_child);
        return root;
    }
};
