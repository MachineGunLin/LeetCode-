class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy -> next = head;
        for(auto cur = dummy; cur -> next && cur -> next -> next;) {
            auto a = cur -> next, b = a -> next;
            cur -> next = b;
            a -> next = b -> next;
            a -> next = b -> next;
            b -> next = a;
            cur = a;
        }
        return dummy -> next;
    }
};
