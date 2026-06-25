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

    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode prev = null;
        ListNode cur = head;
        int count = 1;

        while(count != left){
            prev = cur;
            cur = cur.next;
            count++;
        }

        ListNode reversalStartNode = cur;

        while(count != right){
            cur = cur.next;
            count++;
        }

        ListNode rest = cur.next;
        cur.next = null;

        ListNode newHead = reverseList(reversalStartNode);

        if(prev != null){
            prev.next = newHead;
        }
        
        cur = newHead;

        while(cur.next != null){
            cur = cur.next;
        }

        cur.next = rest;
        
        if(left == 1) return newHead;
        return head;
    }
}