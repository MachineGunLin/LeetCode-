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
    vector<vector<int>> nodes;
    vector<int> res;
    void levelOrder(TreeNode* root) {
        if(root == NULL) {
            return ;
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
            nodes.push_back(nodesOfThisLevel);
        }
    }
    void getRes(TreeNode* root) {
        levelOrder(root);
        for(int i = 0; i < nodes.size(); i++) {
            res.push_back(nodes[i][nodes[i].size() - 1]);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        getRes(root);
        return res;
    }
};
