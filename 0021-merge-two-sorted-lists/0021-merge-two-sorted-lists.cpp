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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode* dummy = new ListNode();
        ListNode* dummyCopy = dummy;

        while(head1 != NULL && head2 != NULL){
            ListNode* newNode;

            if(head1->val < head2->val){
                newNode = new ListNode(head1->val);
                head1 = head1->next;
            }
            else{
                newNode = new ListNode(head2->val);
                head2 = head2->next;
            }

            dummyCopy->next = newNode;
            dummyCopy = dummyCopy->next;   
        }

        while(head1 != NULL){
            ListNode* newNode = new ListNode(head1->val);
            dummyCopy->next = newNode;
            dummyCopy = dummyCopy->next;
            head1 = head1->next;
        }

        while(head2 != NULL){
            ListNode* newNode = new ListNode(head2->val);
            dummyCopy->next = newNode;
            dummyCopy = dummyCopy->next;
            head2 = head2->next;
        }

        return dummy->next;
    }
};