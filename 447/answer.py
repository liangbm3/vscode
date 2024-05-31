from collections import defaultdict

class Solution:
    def numberOfBoomerangs(self, points: list[list[int]]) -> int:
        result=0
        for i in range(len(points)):
            table=defaultdict(int)
            for j in range(len(points)):
                distance=(points[j][0]-points[i][0])**2+(points[j][1]-points[i][1])**2
                table[distance]+=1
            for m in table.values():
                result+=m*(m-1)
        return result
                    
if __name__=="__main__":
    S=Solution()     
    print(S.numberOfBoomerangs([[0,0],[1,0],[2,0]]))
        