/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 Explanation : Concept(Fast And Slow Pointer)
 ---->We took two pointers the first pointer will traverse the distance say, k
 ---->After that the two pointers fast and slow will move together...in this way at last the slow pointer will give the position of the previous node
      which is to be deleted
 ---->We link the pointers as required and then get the answer!
 */
 
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
         ListNode curr = head, prev = head; 
        while((n--) > 0) {
            curr = curr.next;
        }
        if(curr==null) {
            return head.next;
        }
        while(curr.next!=null) {
            curr=curr.next;
            prev=prev.next;
        }
        prev.next = prev.next.next;
        return head;
    }
}
