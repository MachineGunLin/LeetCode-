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
    int tiltSum = 0;
    int getNodeSum(TreeNode* root) {    //计算以root为根的节点的和
        if(root == NULL) return 0;
        return getNodeSum(root -> left) + getNodeSum(root -> right) + root -> val;
    }
    int getNodeTilt(TreeNode* root) {   //计算节点root的坡度
        if(root == NULL) return 0;
        return abs(getNodeSum(root -> left) - getNodeSum(root -> right));
    }
    int findTilt(TreeNode* root) {      //计算以root为根的树的坡度
        if(root == NULL) return 0;
        tiltSum += getNodeTilt(root);
        findTilt(root -> left);
        findTilt(root -> right);
        return tiltSum;
    }
};
