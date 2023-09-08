# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from ..utils.utils import ListNode
from typing import Optional
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head.next == None:
            return head
        
        first = head
        
        if left == 1:
            start = head
        else:
            for i in range(left-2):
                first = first.next
            start = first.next
        
        prev = start
        cur = start.next
        for i in range(right-left):
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        if left == 1:
            head = prev
        else:
            first.next = prev
        
        start.next = cur
        return head   