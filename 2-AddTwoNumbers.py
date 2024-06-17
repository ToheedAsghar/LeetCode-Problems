# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry: int = 0

        if l1 is None:
            return l2
        if l2 is None:
            return l1

        head = None
        curr = None
        
        while l1 is not None and l2 is not None:
            temp: int = l1.val + l2.val + carry
            newNode = ListNode(temp%10)
            carry = temp//10
            if head is None:
                head = curr = newNode
            else:
                curr.next = newNode
                curr = curr.next
            
            l1 = l1.next
            l2 = l2.next

        while l1 is not None:
            temp: int = l1.val + carry
            carry = temp//10
            curr.next = ListNode(temp%10)
            curr = curr.next
            l1 = l1.next

        while l2 is not None:
            temp: int = l2.val + carry
            carry = temp//10
            curr.next = ListNode(temp%10)
            curr = curr.next
            l2 = l2.next

        if carry:
            curr.next = ListNode(carry)

        return head
