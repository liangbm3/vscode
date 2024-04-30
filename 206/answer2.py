# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return
        elif head.next is None:
            return head
        else:
            last=self.reverseList(head.next)
            head.next.next=head
            head.next=None
            return last
if __name__=="__main__":
    answer=Solution()
    a4=ListNode(val=4,next=None)
    a3=ListNode(val=3,next=a4)
    a2=ListNode(val=2,next=a3)
    a1=ListNode(val=1,next=a2)
    head=a1
    res=answer.reverseList(head)
    cur=res
    while cur.next is not None:
        print(cur.val)
        cur=cur.next
    print(cur.val)