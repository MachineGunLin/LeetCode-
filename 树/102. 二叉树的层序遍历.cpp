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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode* pointer = root;
        if(root == NULL) return {};
        q.push(root);
        while(!q.empty()) {
            vector<int> temp = {};
            int length = q.size();
            for(int i = 0; i < length; i++) {
                pointer = q.front();
                q.pop();
                temp.push_back(pointer -> val);
                if(pointer -> left != NULL) q.push(pointer -> left);
                if(pointer -> right != NULL) q.push(pointer -> right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
