# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        list_1=[]
        list_2=[]
        while l1.next is not None:
            list_1.append(l1.val)
            l1=l1.next
        list_1.append(l1.val)
        while l2.next is not None:
            list_2.append(l2.val)
            l2=l2.next
        list_2.append(l2.val)
        num1=0
        num2=0
        index_1=0
        index_2=0
        while list_1:
            num1+=list_1.pop(0)*(10**index_1)
            index_1+=1
        while list_2:
            num2+=list_2.pop(0)*(10**index_2)
            index_2+=1
        result=num1+num2
        result_list=[]
        if result==0:
            return ListNode(0,None)
        n=1
        while result!=0:
            tmp=result%(10**n)
            # if tmp>10:
            #     tmp=tmp//(10**(n-1))
            #     result_list.append(tmp)
            #     break
            result_list.append(tmp//(10**(n-1)))
            result=result-tmp
            n=n+1
        print(result_list)
        if len(result_list)==0:
            return 
        last=ListNode(result_list[-1],None)
        for i in range(len(result_list)-2,-1,-1):
            print(i,end=",")
            tem=ListNode(result_list[i],last)
            # print(result_list[i],end=" ")
            last=tem
        print("\n")
        return last

if __name__=="__main__":
    answer=Solution()
    a11=ListNode(val=9,next=None)
    a10=ListNode(val=9,next=a11)
    a9=ListNode(val=9,next=a10)
    a8=ListNode(val=9,next=a9)
    a7=ListNode(val=9,next=None)
    a6=ListNode(val=9,next=a7)
    a5=ListNode(val=9,next=a6)
    a4=ListNode(val=9,next=a5)
    a3=ListNode(val=9,next=a4)
    a2=ListNode(val=9,next=a3)
    a1=ListNode(val=9,next=a2)
    l1=a1
    l2=a8
    res=answer.addTwoNumbers(l1,l2)
    cur=res
    while cur.next is not None:
        print(cur.val)
        cur=cur.next
    print(cur.val)