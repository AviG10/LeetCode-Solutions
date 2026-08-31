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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = head->next->next;
        int ind = 1;
        vector<int> maxMinIdx;

        while(third != NULL){
            if(second->val > third->val && second->val > first->val){
                maxMinIdx.push_back(ind);
            }

            if(second->val < third->val && second->val < first->val){
                maxMinIdx.push_back(ind);
            }
            
            third = third->next;
            second = second->next;
            first = first->next;

            ind++;
        }

        int n = maxMinIdx.size();

        if(n < 2) 
            return {-1, -1};

        int minDist = INT_MAX;
        int maxDist = INT_MIN;

        for(int i = 1; i < n; i++)
            minDist = min(minDist, maxMinIdx[i] - maxMinIdx[i-1]);
        
        maxDist = maxMinIdx[n-1] - maxMinIdx[0];

        return {minDist, maxDist};
    }
};