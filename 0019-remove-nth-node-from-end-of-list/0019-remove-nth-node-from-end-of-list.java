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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null || head.next == null) return null;

        int cntTotalNode = 1;
        ListNode cur = head;

        while(cur.next != null){
            cur = cur.next;
            cntTotalNode++;
        }

        int deletedNodeIdx = cntTotalNode - n + 1;

        if(deletedNodeIdx == 1) return head.next;

        int cntNode = 1;
        ListNode prev = null;
        cur = head;

        while(cntNode != deletedNodeIdx){
            prev = cur;
            cur = cur.next;
            cntNode++;
        }

        prev.next = cur.next;

        return head;
    }
}