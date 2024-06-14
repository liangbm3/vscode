
class Solution:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:
        self.size=n
        self.mat=[]
        row=0
        self.source=source
        self.destination=destination
        while row<self.size:
            column=0
            line=[]
            while column<self.size:
                line.append(0)
                column+=1
            self.mat.append(line)
            row+=1
        for edge in edges:
            self.mat[edge[0]][edge[1]]=1
            self.mat[edge[1]][edge[0]]=1
        #采用深度优先递归遍历
        self.flag=[0]*self.size
        self.sum=0
        self.result=False
        self.dfs(self.source)
        return self.result
    def dfs(self,cur):
        print("当前顶点：",cur)
        if cur==self.destination:
            self.result=True
            return
        self.sum+=1
        if(self.sum==self.size):
            return False
        for i in range(self.size):
            if self.mat[cur][i]==1 and self.flag[i]==0:
                self.flag[i]=1
                self.dfs(i)
        
        
if __name__=="__main__":
    so=Solution()
    res=so.validPath(n=3,edges=[[0,1],[1,2],[2,0]],source=0,destination=2)
    print(res)