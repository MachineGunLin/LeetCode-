/*
要根据链表节点的值是否大于等于x将链表划分为两段，首先需要链表中大于等于x和小于x的节点的个数，所以无法直接在原链表上做修改。

既然要分开大于等于x的值和小于x的值，我们可以考虑开两个链表，这样按顺序扫描原链表的时候，小于x的值接到第一个链表，大于等于x的值接到第二个链表。

然后再把这两个链表连接起来，就得到了满足题目条件的链表，且节点之间的相对顺序没变。

由于链表里可能一个大于等于x或者小于x的值都不存在，所以开的两个链表是有可能为空的，因此我们需要引入虚拟头节点。

不妨设两个链表的虚拟头节点为leftDummy和rightDummy，然后要遍历原链表，将节点连接到两个新链表，因此两个新链表需要尾指针，分别设为leftTail和rightTail。

这样，遍历一下原链表，如果当前节点的值小于x，则连接到leftTail，然后leftTail向后移动；
如果当前节点的值大于等于x，则连接到rightTail，然后rightTail也向后移动。

遍历完原链表之后，两个新链表就连接起来了小于x和大于等于x的节点了，这时需要连接起来两个链表。
只需要让leftTail -> next = rightDummy -> next;也就第一个链表的尾指针指向第二个链表虚拟头节点的下一个节点（即第一个节点）。
然后还需要rightTail -> next = NULL; 链表最后一个节点的next指针需要指向空。

返回值就是leftTail -> next（虚拟头节点的下一个节点）。
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto leftDummy = new ListNode(-1), rightDummy = new ListNode(-1);      //两个链表的虚拟头节点
        auto leftTail = leftDummy, rightTail = rightDummy;
        for(auto p = head; p != NULL; p = p -> next) {
            if(p -> val < x) {
                leftTail -> next = p;
                leftTail = leftTail -> next;
            } else {
                rightTail -> next = p;
                rightTail = rightTail -> next;
            }
        }
        leftTail -> next = rightDummy -> next;            //连接左右两个链表
        rightTail -> next = NULL;                         //最后一个节点的next指针指向空
        return leftDummy -> next;
    }
};
