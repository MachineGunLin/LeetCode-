/*
链表的“删除”，往往采用的是跳过的方式，即如果p -> next是我们要“删除”的节点，我们只要把p的next指针指向p -> next -> next就可以了，也就是让链表跳过p -> next，让这个节点“社会性死亡”。

根据这个思路，这一题里我们只需要遍历链表，判断节点值是否与我们要删除的相等，如果相等，就跳过这个链表。

不过考虑到有可能链表一开始就是我们要删除的节点，所以我们需要先找到第一个不为要删除的值V的节点，将这个节点作为head，然后从这个节点开始遍历到链表结尾，删除节点。
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
    ListNode* removeElements(ListNode* head, int V) {
        if(head == NULL) {
            return NULL;
        }
        while(head != NULL && head -> val == V) {            //由于链表的开头元素就有可能需要删除，而这时我们还没有节点有next指针指向这个元素呢，因此需要先找到我们的链表头，也就是第一个值不为V的节点
            head = head -> next;
        }
        ListNode* p = head;                        //确定链表头之后，就可以开始遍历链表，根据节点的next指针判断每个节点是否要删除了
        while(p != NULL) {
            if(p -> next != NULL && p -> next -> val == V) {      //删除的情况就是，p的下一个节点不为空，且下一个节点值就是我们要删除的值
                p -> next = p -> next -> next;
            } else {                              //继续往后找
                p = p -> next;
            }
        }
        return head;
    }
};
