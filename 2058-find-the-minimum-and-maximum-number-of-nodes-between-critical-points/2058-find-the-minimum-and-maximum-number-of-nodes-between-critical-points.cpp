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
        vector<int> minMaxIdx;

        while (third != NULL) {
            if (second->val > first->val && second->val > third->val)
                minMaxIdx.push_back(ind);

            if (second->val < first->val && second->val < third->val)
                minMaxIdx.push_back(ind);

            ind++;

            first = first->next;
            second = second->next;
            third = third->next;
        }

        int n = minMaxIdx.size();

        if (n < 2)
            return {-1, -1};

        int maxDistance = minMaxIdx[n - 1] - minMaxIdx[0];

        int minDistance = minMaxIdx[1] - minMaxIdx[0];

        for (int i = 2; i < n; i++)
            minDistance = min(minDistance, minMaxIdx[i] - minMaxIdx[i - 1]);

        return {minDistance, maxDistance};
    }
};