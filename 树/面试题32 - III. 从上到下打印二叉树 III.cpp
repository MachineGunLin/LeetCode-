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
        int level = 0;
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            deque<int> nodesOfThisLevel;
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(level % 2 == 0) {
                    nodesOfThisLevel.push_back(temp -> val);    
                } else {
                    nodesOfThisLevel.push_front(temp -> val); 
                }
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);    
            }
            res.push_back(vector<int>(nodesOfThisLevel.begin(), nodesOfThisLevel.end()));
            level++;
        }
        return res;
    }
};
