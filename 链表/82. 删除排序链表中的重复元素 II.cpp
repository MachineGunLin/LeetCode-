/*
题意是要删除一个排序链表里所有重复出现的数字，链表里留下的数字都是只出现一次的数字。

思路：用两个指针currentNode和nextNode扫描一遍有序链表，最开始初始化currentNode为链表的附加头节点dummy,
nextNode为currentNode的下一个节点，然后不断判断nextNode当前所指的节点的数的个数。

判断的方式是将nextNode移动到第一个和currentNode -> next所指节点的值不相等的节点，然后判断currentNode -> next的
next指针是否指向nextNode（current -> next -> next == nextNode ? )

如果是，说明currentNode的下一个数字只出现了一次，
可以不删除，让currentNode移动到next指针所指的节点去(currentNode = currentNode -> next)；

如果不是，说明currentNode的下一个节点的数字出现了多次，需要全部删除，删除的方法也很简单，直接将currentNode的next指针
指向nextNode即可（currentNode -> next = nextNode），因为nextNode是第一个和原来currentNode的下一个节点的数字不相等的节点。

比如，对于样例  1->2->3->3->4->4->5
最开始currentNode = dummy, nextNode = currentNode -> next(也是就1）, 
我们将nextNode移动到第一个和1(currentNode -> next)不相等的数字上 -> 

while(nextNode && currentNode -> next -> val == nextNode -> val) {
      nextNode = nextNode -> next;
}


这样nextNode现在就指向了2，然后判断currentNode -> next -> next和nextNode的关系，发现相等（说明数字1只出现了一次），
可以不删除： currentNode = currentNode -> next;

然后继续判断，这时currentNode为2，nextNode重新赋值为currentNode -> next(就是3），
通过上面那个while循环，nextNode移动到了第一个和3不相等的节点4，判断current -> next -> next和nextNode的关系，发现不相等，
说明数字3出现了多次，需要删除，直接将currentNode的next节点指向nextNode（也就是4），这样就删除掉了所有重复的3.

。。。。。。

一直下去，直到currentNode的next指向空，扫描完整个有序链表。
*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy -> next = head;
        auto currentNode = dummy;
        while(currentNode -> next) {
            auto nextNode = currentNode -> next;
            while(nextNode && currentNode -> next -> val == nextNode -> val) {
                nextNode = nextNode -> next;
            }
            if(currentNode -> next -> next == nextNode) {
                currentNode = currentNode -> next;
            } else {
                currentNode -> next = nextNode;
            }
        }
        return dummy -> next;
    }
};
