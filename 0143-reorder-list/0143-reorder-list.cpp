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
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur != NULL){
            ListNode* curNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = curNext;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        
        ListNode* midNode = middleNode(head);
        ListNode* right = reverseList(midNode);
        ListNode* left = head;

        while(right != midNode){
            ListNode* rightNext = right->next;
            ListNode* leftNext = left->next;

            left->next = right;
            left->next->next = leftNext;
            left = left->next->next;

            right = rightNext;
        }
    }
};