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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        if(K == 0) {
            res.push_back(target -> val);
            return res;
        }
        map<TreeNode*, TreeNode*> treeMap;
        treeToMap(root, treeMap);
        queue<TreeNode*> q;
        set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int distance = 0;
        while(!q.empty()) {
            int length = q.size();
            distance++;
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp -> left != NULL && visited.count(temp -> left) == 0) {
                    q.push(temp -> left);
                    visited.insert(temp -> left);
                    if(distance == K) {
                        res.push_back(temp -> left -> val);
                    }
                }
                if(temp -> right != NULL && visited.count(temp -> right) == 0) {
                    q.push(temp -> right);
                    visited.insert(temp -> right);
                    if(distance == K) {
                        res.push_back(temp -> right -> val);
                    }
                }
                if(treeMap[temp] != NULL && visited.count(treeMap[temp]) == 0) {
                    q.push(treeMap[temp]);
                    visited.insert(treeMap[temp]);
                    if(distance == K) {
                        res.push_back(treeMap[temp] -> val);
                    }
                }
            }
            if(distance == K) {
                break;
            }
        }
        return res;
    }
};
