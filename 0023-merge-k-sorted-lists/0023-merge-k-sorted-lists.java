/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null)
            return list2;
        if (list2 == null)
            return list1;

        ListNode node = new ListNode();

        if (list1.val < list2.val) {
            node.val = list1.val;
            node.next = mergeTwoLists(list1.next, list2);
        } else {
            node.val = list2.val;
            node.next = mergeTwoLists(list1, list2.next);
        }

        return node;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;

        if (n == 0)
            return null;
        if (n == 1)
            return lists[0];

        ListNode newHead = mergeTwoLists(lists[0], lists[1]);

        if (n == 2)
            return newHead;

        for (int i = 2; i < n; i++) {
            newHead = mergeTwoLists(newHead, lists[i]);
        }

        return newHead;
    }
}