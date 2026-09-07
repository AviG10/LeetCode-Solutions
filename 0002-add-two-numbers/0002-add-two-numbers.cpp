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
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int sum = 0;

            if (l1 != NULL)
                sum += l1->val;

            if (l2 != NULL)
                sum += l2->val;

            sum += carry;

            cur->next = new ListNode(sum % 10);
            carry = sum / 10;

            cur = cur->next;

            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        if (carry > 0) {
            cur->next = new ListNode(carry);
        }

        return dummy->next;
    }
};