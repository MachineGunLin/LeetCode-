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
    int sum;
    void BFS(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return ;
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                sum++;
                q.pop();
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }   
        }
    }
    int countNodes(TreeNode* root) {
        BFS(root);
        return sum;
    }
};
