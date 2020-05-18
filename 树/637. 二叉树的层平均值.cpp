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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            double sumOfLevels = 0;
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                sumOfLevels += temp -> val;
                q.pop();
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            res.push_back(sumOfLevels / length);   
        }
        return res;
    }
};
