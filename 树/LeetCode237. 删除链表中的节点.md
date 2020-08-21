# LeetCode237. 删除链表中的节点

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200821103638944-724547156.png)

这题给出的节点是要删除的节点，而不是要删除的节点的前驱节点，所以，如果直接把这个节点删掉的话，单链表就断掉了，
没办法，所以不能动这个要删除的节点，不过我们可以动这个要删除的节点的下一个节点，但是下一个节点不是我们要删除的节点，
因为他的值我们需要保留，正好我们可以把我们现在指向的节点node的值修改为node->next的值，然后让node的next指针直接指向
node->next的next，这样就把下一个节点给跳过了。达到了一个“曲线删除节点”的效果。

```
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
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
```