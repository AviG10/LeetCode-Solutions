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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int count = 0;
        ListNode* node = head;

        while(node->next != NULL){
            node = node->next;
            count++;
        }
        count++;

        int iteration = count - (k % count);
        node->next = head;
        
        while(iteration--){
            node = node->next;
        }

        head = node->next;
        node->next = NULL;

        return head;
    }
};