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
        cur=head
        i=1
        while cur.next is not None:
            i=i+1
            cur=cur.next
        cur=head
        stack=[]
        stack.append(cur.val)
        k=1
        while cur.next is not None:
            if not stack:
                stack.append(cur.next.val)
            elif cur.next.val==stack[-1]:
                if i%2!=0 and k==(i+1)/2-1:
                    pass
                else:
                    stack.pop()
            else:
                if i%2!=0 and k==(i+1)/2-1:
                    pass
                else:
                    stack.append(cur.next.val)
                    print(cur.next.val,k)
            cur=cur.next
            k=k+1
        if not stack:
            return True
        else:
            return False
if __name__=="__main__":
    answer=Solution()
    a6=ListNode(val=1,next=None)
    a5=ListNode(val=0,next=a6)
    a4=ListNode(val=4,next=a5)
    a3=ListNode(val=3,next=a4)
    a2=ListNode(val=0,next=a3)
    a1=ListNode(val=1,next=a2)
    head=a1
    res=answer.isPalindrome(head)
    print(res)