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
    void BFS(TreeNode* root) {
        if(root == NULL) return ;
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
    int findBottomLeftValue(TreeNode* root) {
        BFS(root);
        int numOfLevels = nodes.size();
        return nodes[numOfLevels - 1][0];
    }
};
