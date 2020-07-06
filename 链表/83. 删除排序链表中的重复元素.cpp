/*
判断当前节点currentNode的值和它的next指针所指向的节点的值是否相等，如果相等，就一直向后移动next指针直到遇到
next指针所指节点的值和currentNode的值不相等，这时将currentNode的next指针指向这个不相等的节点即可。
当currentNode和currentNode的next指针都为空时退出while循环，表示扫描链表结束（currentNode为空表示链表末尾已经指向NULL）。
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto currentNode = head;
        while(currentNode && currentNode -> next) {
            if(currentNode -> val == currentNode -> next -> val) {
                currentNode -> next = currentNode -> next -> next;
            } else {
                currentNode = currentNode -> next;
            }
        }
        return head;
    }
};
