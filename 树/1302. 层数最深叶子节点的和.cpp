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
    int getHeight(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        if(root -> left == NULL && root -> right == NULL) {
            return 1;
        }
        return max(getHeight(root -> left), getHeight(root -> right)) + 1;
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int height = getHeight(root);
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int res = 0;
        while(!q.empty()) {
            int length = q.size();
            level++;
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(level == height) {
                    res += temp -> val; 
                }
                if(temp -> left != NULL) {
                    q.push(temp -> left);
                }
                if(temp -> right != NULL) {
                    q.push(temp -> right);
                }
            }
        }
        return res;
    }
};
