//自己写的写法太复杂了，下次碰到，参考一下官方题解

class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        if(root -> left == NULL && root -> right == NULL) {
            return root -> val;
        }
        if(root -> left == NULL) {
            int rrrl = 0, rrrr = 0;
            if(root -> right -> left != NULL) {
                rrrl = rob(root -> right -> left);
            }
            if(root -> right -> right != NULL) {
                rrrr = rob(root -> right -> right);
            }
            return max(rob(root -> right), root -> val + rrrl + rrrr);
        }
        if(root -> right == NULL) {
            int rrll = 0, rrlr = 0;
            if(root -> left -> left != NULL) {
                rrll = rob(root -> left -> left);
            }
            if(root -> left -> right != NULL) {
                rrlr = rob(root -> left -> right);
            }
            return max(rob(root -> left), root -> val + rrll + rrlr);
        }
        int rrll = 0, rrlr = 0, rrrl = 0, rrrr = 0;
        if(root -> left -> left != NULL) {
            rrll = rob(root -> left -> left);
        }
        if(root -> left -> right != NULL) {
            rrlr = rob(root -> left -> right);
        }
        if(root -> right -> left != NULL) {
            rrrl = rob(root -> right -> left);
        }
        if(root -> right -> right != NULL) {
            rrrr = rob(root -> right -> right);
        }
        return max(rob(root -> left) + rob(root -> right), root -> val + rrll + rrlr + rrrl + rrrr);
    }
};
