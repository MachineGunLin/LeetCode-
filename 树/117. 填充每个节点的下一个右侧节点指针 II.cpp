/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void BFS(Node* root) {
        if(root == NULL) {
            return ;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            for(int i = 1; i <= length; i++) {
                Node* currentNode = q.front();
                q.pop();
                if(i <= length - 1) {
                    Node* nextNode = q.front();
                    if(nextNode != NULL) {
                        currentNode -> next = nextNode;
                    }
                }
                if(currentNode -> left != NULL) q.push(currentNode -> left);
                if(currentNode -> right != NULL) q.push(currentNode -> right);
            }
        }
    }
    Node* connect(Node* root) {
        BFS(root);
        return root;
    }
};
