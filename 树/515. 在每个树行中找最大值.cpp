/*
层次遍历，找出每一行的最大值。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;

    void BFS(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> nodesOfThiLevel;
            for(int i = 0; i < size; ++i) {
                auto t = q.front();
                q.pop();
                nodesOfThiLevel.push_back(t -> val);
                if(t -> left != NULL) {
                    q.push(t -> left);
                }
                if(t -> right != NULL) {
                    q.push(t -> right);
                }
            }
            res.push_back(*max_element(nodesOfThiLevel.begin(), nodesOfThiLevel.end()));
        }
    }

    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        BFS(root);
        return res;
    }
};
