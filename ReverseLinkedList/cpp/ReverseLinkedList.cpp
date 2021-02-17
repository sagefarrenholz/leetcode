class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* after = nullptr;
        while (head != nullptr) {
            after = new ListNode(head->val, after);
            head = head->next;
        }
        return after;
    }
};
