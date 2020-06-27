/*
要将链表向右移动 k 次，可以将链表分为两部分：不移动部分和移动部分。
不移动部分就是链表前 size - k 个结点（size为链表结点个数），移动部分就是链表后 k 个结点。
对于移动部分的 k 个结点，需要将第一个结点置为新的 head 结点，并且移动部分的最后一个节点的 next 指针指向不移动部分的第一个结点。
而对于移动部分，需要将最后一个结点的 next 指针指向NULL，因为这个结点是新链表的尾结点。
具体见代码：
*/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) {            //特判，如果头节点为空或者无需移动
            return head;                        //直接返回原来的链表即可
        }
        ListNode* tail;                         //tail表示最后一个非空节点，也就是移动部分的最后一个节点
        int size = 0;                           //size表示链表非空节点的个数，k需要对size取余
        for(ListNode* p = head; p != NULL; p = p -> next) {
            tail = p;                           //找到尾节点
            ++size;                             //并计算链表大小
        }
        k = k % size;                           //k需要对size取余，因为每移动size次就等于没移动
        if(k == 0) {                            //如果k为0，就无需移动
            return head;
        }
        ListNode* first = head;                  //first表示移动部分的最后一个节点
        for(int i = 0; i < size - k - 1; ++i) {  //因为移动部分有 n - k 个节点，所以从head往后 n - k - 1 次就找到了移动部分的最后一个节点first
            first = first -> next;
        }
        tail -> next = head;                     //移动部分放到了不移动部分的前面，所以移动部分的尾节点的next指针指向移动部分的第一个节点head
        head = first -> next;                    //此时不移动部分的最后一个节点first的next指针指向移动部分的第一个节点，而移动部分的第一个节点就是新链表的头节点，所以更新一下
        first -> next = NULL;                    //因为first是新链表的尾结点，所以first的next指针指向NULL
        return head;
    }
};
