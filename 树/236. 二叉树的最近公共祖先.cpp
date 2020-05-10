## 思路
如果二叉树为空，则返回空，如果两个节点其中一个已经是root，则返回这个节点。
然后递归左右子树，因为是递归，所以可以认为左右子树已经计算出结果，分别用left和right表示。
如果left为空，就要看right的状态，反之亦然。
如果left和right都非空，由于只有p和q两个节点，说明p和q分别在左右子树一边一个，所以root是最近公共祖先，返回root。
如果left和right都为空，则返回空。


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if(left != NULL && right != NULL) {
            return root;
        }
        return left != NULL ? left : right;
    }
};
