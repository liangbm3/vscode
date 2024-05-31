class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        total_size=len(points)
        heap_list=[]
        current_size=0
        result=[]
        for i in range(total_size):
            heap_list.append([points[i][0]**2+points[i][1]**2,points[i][0],points[i][1]])
            current_size+=1
            m=current_size-1
            while(m>=1 and (m-1)//2>=0):
                parent=(m-1)//2
                if heap_list[m][0]<heap_list[parent][0]:
                    heap_list[m],heap_list[parent]=heap_list[parent],heap_list[m]
                m=parent
        if k<total_size:
            for j in range(k-1):
                result.append([heap_list[j][1],heap_list[j][2]])
            if heap_list[k-1][0]<heap_list[k][0]:
                result.append([heap_list[k-1][1],heap_list[k-1][2]])
            else:
                result.append([heap_list[k][1],heap_list[k][2]])
        else:
            for j in range(k):
                result.append([heap_list[j][1],heap_list[j][2]])
        return result
        
if __name__ =="__main__":
    answer=Solution()
    result=answer.kClosest(points=[[0,1],[1,0]],k=2)
    print(result)
    