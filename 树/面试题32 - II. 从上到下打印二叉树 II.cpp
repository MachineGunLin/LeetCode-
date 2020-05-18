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
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            vector<int> nodesOfThisLevel; 
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                q.pop();
                nodesOfThisLevel.push_back(temp -> val);
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            res.push_back(nodesOfThisLevel);
        }
        return res;
    }
};
