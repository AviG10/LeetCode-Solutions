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
private:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* mergeTwoSortedList(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        if (temp1 != NULL)
            temp->next = temp1;
        else
            temp->next = temp2;

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* midNode = findMid(head);

        ListNode* right = midNode->next;
        midNode->next = NULL;

        ListNode* left = head;

        ListNode* leftSortedList = sortList(left);
        ListNode* rightSortedList = sortList(right);

        return mergeTwoSortedList(leftSortedList, rightSortedList);
    }
};