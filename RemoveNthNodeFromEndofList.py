# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0)
        dummy.next = head
        p = q = dummy
        
        for i in range(n):
            q = q.next
        
        while q.next != None:
            p = p.next
            q = q.next
        
        p.next = p.next.next
        
        return dummy.next
