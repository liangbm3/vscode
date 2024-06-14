from collections import deque
class Solution:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:
        self.size=n
        self.adj_list=dict()
        result=False
        for i in range(self.size):
            self.adj_list[i]=[]
        for edge in edges:
            vet1=edge[0]
            vet2=edge[1]
            self.adj_list[vet1].append(vet2)
            self.adj_list[vet2].append(vet1)
        visited=set()
        visited.add(source)
        que=deque()
        que.append(source)
        while len(que)>0:
            vet=que.popleft()
            if vet==destination:
                result=True
                break
            for adj_vet in self.adj_list[vet]:
                if adj_vet in visited:
                    continue
                que.append(adj_vet)
                visited.add(adj_vet)
        return result
    
    
if __name__=="__main__":
    so=Solution()
    res=so.validPath(n=3,edges=[[0,1],[1,2],[2,0]],source=0,destination=2)
    print(res)