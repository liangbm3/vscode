class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        self.heap_list=[]
        self.current_size=0
        self.current_size=len(points)
        result=[]
        for i in range(self.current_size):
            self.heap_list.append([points[i][0]**2+points[i][1]**2,points[i][0],points[i][1]])
        j=len(points)//2-1
        while j>=0:
            self.perc_down(j)
            j-=1
        for m in range(k):
            result.append([self.heap_list[0][1],self.heap_list[0][2]])
            self.heap_list[0]=self.heap_list[self.current_size-1]
            self.current_size-=1
            self.heap_list.pop()
            self.perc_down(0)
        return result
    def perc_down(self,i):
        while (i*2 +1)<self.current_size:
            mc=self.minChild(i)
            if self.heap_list[i][0]>self.heap_list[mc][0]:
                self.heap_list[i],self.heap_list[mc]=self.heap_list[mc],self.heap_list[i]
            i=mc
            
    def minChild(self, i):
        if i * 2 + 2 >= self.current_size:
            return i * 2 + 1
        else:
            if self.heap_list[i * 2 + 1][0] < self.heap_list[i * 2 + 2][0]:
                return i * 2 + 1
            else:
                return i * 2 + 2

if __name__ =="__main__":
    answer=Solution()
    result=answer.kClosest(points=[[0,1],[1,0]],k=2)
    print(result)