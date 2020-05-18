/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> res;
        queue<TreeNode*> q;
        q.push(tree);
        while(!q.empty()) {
            int length = q.size();
            ListNode* head = new ListNode(-1);
            ListNode* headNode = head;
            for(int i = 0; i < length; i++) {
                TreeNode* temp = q.front();
                q.pop();
                ListNode* node = new ListNode(temp -> val);
                headNode -> next = node;
                headNode = headNode -> next;
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            res.push_back(head -> next);
        }
        return res;
    }
};
