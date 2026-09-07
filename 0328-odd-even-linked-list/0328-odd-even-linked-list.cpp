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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;

        ListNode* oddListHead = head;
        ListNode* evenListHead = head->next;

        ListNode* evenListHeadCopy = evenListHead;

        while(evenListHead != NULL && evenListHead->next != NULL){
            oddListHead->next = oddListHead->next->next;
            oddListHead = oddListHead->next;
            
            evenListHead->next = evenListHead->next->next;
            evenListHead = evenListHead->next;
        }

        oddListHead->next = evenListHeadCopy;
        return head;
    }
};