class Solution:
    def baseNeg2(self, n: int) -> str:
        li=[]
        string=""
        while n!=0:
            li.append(n%2)
            n=n//2
        total=0
        for i in range(len(li)):
            print(li)
            total+=(-2)**li[i]
            print(total)
        
s=Solution()
string=s.baseNeg2(2)
print(string)