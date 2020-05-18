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
    void treeToMap(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if(root == NULL) {
            return ;
        }
        if(root -> left != NULL) {
            mp[root -> left] = root;
        }
        if(root -> right != NULL) {
            mp[root -> right] = root;
        }
        treeToMap(root -> left, mp);
        treeToMap(root -> right, mp);
    } 
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int sum = 0;
        map<TreeNode*, TreeNode*> treeMap;
        treeToMap(root, treeMap);
        set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited.insert(root);
        while(!q.empty()) {
            int length = q.size();
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(treeMap[temp] != NULL && treeMap[treeMap[temp]] != NULL) {
                    if(treeMap[treeMap[temp]] -> val % 2 == 0) {
                        sum += temp -> val;
                    }
                }
                if(temp -> left != NULL && visited.count(temp -> left) == 0) {
                    q.push(temp -> left);
                    visited.insert(temp -> left);
                }
                if(temp -> right != NULL && visited.count(temp -> right) == 0) {
                    q.push(temp -> right);
                    visited.insert(temp -> right);
                }
                /*if(treeMap[temp] != NULL && visited.count(treeMap[temp]) == 0) {
                    q.push(treeMap[temp]);
                    visited.insert(treeMap[temp]);
                }*/
            }
        }
        return sum;
    }
};
