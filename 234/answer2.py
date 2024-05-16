# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head.next==None:
            return True
        else:
            li=[]
            cur=head
            while cur.next is not None:
                li.append(cur.val)
                cur=cur.next
            li.append(cur.val)
        while True:
            if not li or len(li)==1:
                return True
            if li[0]==li[-1]:
                li.pop(0)
                li.pop()
            else:
                return False
if __name__=="__main__":
    answer=Solution()
    a6=ListNode(val=1,next=None)
    a5=ListNode(val=0,next=a6)
    a4=ListNode(val=0,next=a5)
    a3=ListNode(val=0,next=a4)
    a2=ListNode(val=0,next=a3)
    a1=ListNode(val=1,next=a2)
    head=a1
    res=answer.isPalindrome(head)
    print(res)