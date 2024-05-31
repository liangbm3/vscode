from collections import defaultdict
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> list[str]:
        result=[]
        length=10
        table=defaultdict(int)
        for i in range(len(s)-length+1):
            sub_s=s[i:i+length]
            table[sub_s]+=1
            if table[sub_s]==2:
                result.append(sub_s)
        return result
            