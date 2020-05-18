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
    map<int, int> getDepth;
    void levelOrderTraversal(TreeNode* root) {
        if(root == NULL) {
            return ;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int length = q.size();
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                q.pop();
                getDepth[temp -> val] = level;
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            level++;
        }
    }
    bool isBrothers(TreeNode* root, int x, int y) {
        if(root == NULL) {
            return false;
        }
        if(root -> left == NULL && root -> right == NULL) {
            return false;
        }
        if(root -> left == NULL) {
            return isBrothers(root -> right, x, y);
        }
        if(root -> right == NULL) {
            return isBrothers(root -> left, x, y);
        }
        if((root -> left -> val == x && root -> right -> val == y) || (root -> left -> val == y && root -> right -> val == x)) {
            return true;
        }
        return isBrothers(root -> left, x, y) || isBrothers(root -> right, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL || root -> val == x || root -> val == y) {
            return false;
        }
        levelOrderTraversal(root);
        return !isBrothers(root, x, y) && getDepth[x] == getDepth[y];
    }
};
