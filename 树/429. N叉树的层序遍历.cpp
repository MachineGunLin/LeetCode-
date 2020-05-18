/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> res;
    void levelOrderTraversal(Node* root) {
        if(root == NULL) return ;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            vector<int> nodesOfThisLevel;
            for(int i = 0; i < length; i++) {
                Node* temp = q.front();
                nodesOfThisLevel.push_back(temp -> val);
                q.pop();
                for(auto child : temp -> children) {
                    q.push(child);
                }
            }
            res.push_back(nodesOfThisLevel);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        levelOrderTraversal(root);
        return res;
    }
};
