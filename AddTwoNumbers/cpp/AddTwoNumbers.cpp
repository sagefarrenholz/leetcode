/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* sum = new ListNode(l1->val + l2->val);
        //if (sum->val >=)
        sum->next = addTwoNumbers(l1->next, l2->next);
        if (sum->val >= 10) {
            sum->val -= 10;
            if (sum->next == nullptr) sum->next = new ListNode(1);
            else sum->next = addTwoNumbers(sum->next, new ListNode(1));
        }
        return sum;
    }
};
