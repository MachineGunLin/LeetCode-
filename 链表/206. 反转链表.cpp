/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
 翻转一个链表，考虑用栈（栈有后进先出的特性）。
 注意一下实现细节：
 栈最开始要压入一个空指针: st.push(NULL); 这是方便最后反转的时候尾元素的next指针直接指向NULL。
 另外就是要额外开辟一个currentNode的空间来遍历栈/链表，因为返回的是头指针，是不能动的。
 */
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        stack<ListNode*> st;
        st.push(NULL);
        while(head != NULL) {
            st.push(head);
            head = head -> next;
        }
        head = st.top();
        st.pop();
        ListNode* currentNode = head;
        while(!st.empty()) {
            currentNode -> next = st.top();
            st.pop();
            currentNode = currentNode -> next;
        }
        return head;
    }
};
