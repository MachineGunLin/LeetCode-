/*
可以利用栈的性质，遍历链表，把节点存入栈中，然后一个一个弹栈，连接成新链表。
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        stack<ListNode*> st;
        ListNode* cur = head;            //cur指针指向当前正在处理的节点
        while(cur != NULL) {
            st.push(cur);
            cur = cur -> next;
        }
        cur = head = st.top();            //栈顶元素就是新链表的头节点
        st.pop();
        while(!st.empty()) {
            cur -> next = st.top();
            st.pop();
            cur = cur -> next;
        }
        cur -> next = NULL;
        return head;
    }
};
