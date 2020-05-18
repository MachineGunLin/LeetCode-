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
    set<int> s;
    void inOrderTraversal(TreeNode* root) {
        if(root == NULL) return ;
        inOrderTraversal(root -> left);
        s.insert(root -> val);
        inOrderTraversal(root -> right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inOrderTraversal(root);
        if(s.size() < 2) return -1;
        int cnt = 0;
        for(auto it = s.begin(); it != s.end(); ++it) {
            if(cnt == 1) {
                return *it;
            }
            ++cnt;
        }
        return -1;
    }
};
