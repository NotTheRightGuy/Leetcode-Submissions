# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1, l2, carry=0):
        if not l1 and not l2 and not carry: return None
        csum = carry
        if l1:
            csum += l1.val
            l1=l1.next
        if l2:
            csum+=l2.val
            l2=l2.next
        head = ListNode(csum%10, self.addTwoNumbers(l1,l2,csum>9))
        return head
        