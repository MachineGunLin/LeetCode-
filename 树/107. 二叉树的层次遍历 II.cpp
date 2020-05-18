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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> reverseRes = {};
        vector<vector<int>> res = {};
        queue<TreeNode*> q;
        stack<vector<int>> s;
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
            reverseRes.push_back(temp);
        }
        vector<vector<int>>::iterator it = reverseRes.begin();
        for(; it != reverseRes.end(); it++) {
            s.push(*it);
        }
        vector<int> temp = {};
        while(!s.empty()) {
            temp = s.top();
            res.push_back(temp);
            s.pop();
        }
        return res;
    }
};
