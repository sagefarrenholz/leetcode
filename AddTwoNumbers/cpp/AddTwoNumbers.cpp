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
	if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        l1->val += l2->val;
        l1->next = addTwoNumbers(l1->next, l2->next);
        if (l1->val >= 10) {
            l1->val -= 10;
            l1->next = addTwoNumbers(l1->next, new ListNode(1));
        }
        return l1;
     }
};
