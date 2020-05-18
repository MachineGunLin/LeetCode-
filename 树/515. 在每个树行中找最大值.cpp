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
    void BFS(TreeNode* root) {
        if(root == NULL) return ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            set<int> s;
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                q.pop();
                s.insert(temp -> val);
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            nodes.push_back(vector<int>(s.begin(), s.end()));
        }
    }
    void getRes(TreeNode* root) {
        BFS(root);
        int levels = nodes.size();
        for(int i = 0; i < levels; i++) {
            int length = nodes[i].size();
            res.push_back(nodes[i][length - 1]);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        getRes(root);
        return res;
    }
};
