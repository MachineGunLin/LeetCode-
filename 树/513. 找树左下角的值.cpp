/*
树的最后一行的最左边的值，也就是层次遍历时树的最后一行的第一个遍历到的节点。
因此我们可以对树做一个层次遍历，遍历到的节点存在一个二维vector里，每一维vector存放一行树的节点。
遍历结束之后，直接返回最后一层的第一个节点，就是答案。
*/

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
    vector<vector<int>> nodes;                  // nodes存放层次遍历二叉树的节点

    void BFS(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> nodesOfThisLevel;            // nodesOfThisLevel表示当前这一层的所有节点
            for(int i = 0; i < size; ++i) {
                auto t = q.front();
                q.pop();
                nodesOfThisLevel.push_back(t -> val);
                if(t -> left != NULL) {
                    q.push(t -> left);
                }
                if(t -> right != NULL) {
                    q.push(t -> right);
                }
            }
            nodes.push_back(nodesOfThisLevel);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        BFS(root);
        return nodes.back().front();                     // 二叉树层次遍历最后一层的第一个节点就是树左下角的值
    }
};
