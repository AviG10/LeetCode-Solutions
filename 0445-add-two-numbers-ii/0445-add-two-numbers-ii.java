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
    private ListNode reverseList(ListNode head){
        ListNode prev = null;
        ListNode cur = head;

        while(cur != null){
            ListNode tempNode = cur.next;
            cur.next = prev;
            prev = cur;
            cur = tempNode;
        }

        return prev;
    }

    private ListNode addTwoNumbersReverse(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        ListNode head1 = l1;
        ListNode head2 = l2;
        int carry = 0;

        while(head1 != null || head2 != null){
            int sum = 0;
            
            if(head1 != null) sum += head1.val;
            if(head2 != null) sum += head2.val;

            sum += carry;

            ListNode node = new ListNode(sum % 10);
            carry = sum / 10;

            cur.next = node;
            cur = cur.next;

            if(head1 != null) head1 = head1.next;
            if(head2 != null) head2 = head2.next;
        }

        if(carry > 0) {
            ListNode node = new ListNode(carry);
            cur.next = node;
        }

        return dummy.next;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode newHeadL1 = reverseList(l1);
        ListNode newHeadL2 = reverseList(l2);

        ListNode headReverseAddNumbers = addTwoNumbersReverse(newHeadL1, newHeadL2);

        return reverseList(headReverseAddNumbers);
    }
}