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
    map<int, int> mp;
    map<int, int>::iterator it;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        inOrderTraversal(root);
        int maxFrefuency = 0;
        for(it = mp.begin(); it != mp.end(); it++) {
            if(it -> second > maxFrefuency) {
                maxFrefuency = it -> second;
            }
        }
        for(it = mp.begin(); it != mp.end(); it++) {
            if(it -> second == maxFrefuency) {
                res.push_back(it -> first);
            }
        }
        return res;
    }
    void inOrderTraversal(TreeNode* root) {
        if(root == NULL) return ;
        inOrderTraversal(root -> left);
        mp[root -> val]++;
        inOrderTraversal(root -> right);
    }
};
