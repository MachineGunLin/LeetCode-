/*
这题做法比较贼，让两个指针p, q分别指向两个链表的头，然后只要两个指针不为空且指向的位置不同，就都向后移动，当一个指针为空的时候，就指向另一个链表的头。

![](https://img2020.cnblogs.com/blog/2078361/202007/2078361-20200731213418149-2023923953.png)

比如上面这图，假设相交部分之前，两个链表的长度分别是a，b，相交链表之后的长度为c。

那么p指针走了a + c长度（走完第一个链表）之后，指向第二个链表头headB；
q指针走了b + c长度（走完第二个链表）之后，指向第一个链表头headA。

然后两个指针又分别走了b和a的长度，最终，在经过a + b + c之后，两个指针终于相遇了。
这是两个链表有交点的情况。

如果两个链表没有交点，这种走法也是成立的。
![](https://img2020.cnblogs.com/blog/2078361/202007/2078361-20200731213708660-1113401136.png)

比如上图，p走完第一个链表（经过a步），走到了第二个链表头headB；q走完第二个链表（经过b步），走到了第一个链表头headA。
然后它们右各自走了b步和a步，都到了NULL，注意，是NULL哦，两个指针都指向NULL了，也可以认为指向相同的位置，所以返回值是p（或者q也行，反正都是NULL）。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while(p != q) {
            if(p != NULL) {
                p = p -> next;
            } else {
                p = headB;
            }
            if(q != NULL) {
                q = q -> next;
            } else {
                q = headA;
            }
        }
        return p;
    }
};
