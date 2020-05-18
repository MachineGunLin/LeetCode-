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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> res;
        DFS(root, path, res);
        return res;
    }
    void DFS(TreeNode* root, string path, vector<string>& res) {
        if(root == NULL) return ;
        path += to_string(root -> val);
        path += "->";
        if(root -> left == NULL && root -> right == NULL) {
            path.erase(path.length() - 2);
            res.push_back(path);
        }
        DFS(root -> left, path, res);
        DFS(root -> right, path, res);
    }
};
