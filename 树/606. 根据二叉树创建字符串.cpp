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
    string tree2str(TreeNode* t) {
        if(t == NULL) {
            return "";
        }
        const string s = to_string(t -> val);
        const string left = tree2str(t -> left);
        const string right = tree2str(t -> right);
        if(t -> left == NULL && t -> right == NULL) {
            return s;
        }
        if(t -> right == NULL) {
            return s + '(' + left + ')';
        }
        return s + '(' + left + ')' + '(' + right + ')';
    }
};
