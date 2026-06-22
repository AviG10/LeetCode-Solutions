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
    int pairSum(ListNode* head) {
        // Step - 1 : Finding Mid Node
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;

        // Step - 2 : Reversing 2nd Half of Linked List
        ListNode* prev = NULL;
        ListNode* cur = mid;
        
        while(cur != NULL){
            ListNode* next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }

        // Step - 3 : Finding Maximum
        int ans = 0;
        
        ListNode* firstHalfHead = head;
        ListNode* secondHalfHead = prev;

        while(secondHalfHead != NULL){
            ans = max(ans, firstHalfHead->val + secondHalfHead->val);
            
            firstHalfHead = firstHalfHead->next;
            secondHalfHead = secondHalfHead->next;
        }

        return ans;
    }
};