from collections import deque
class Solution:
    def findCircleNum(self, isConnected: list[list[int]]) -> int:
        self.map=isConnected
        self.size=len(self.map)
        #采用深度优先递归遍历
        self.flag=[0]*self.size
        self.sum=0
        self.result=0
        for i in range(self.size):
            if self.flag[i]==0:
                self.dfs(i)
                self.result+=1
        return self.result
    def dfs(self,cur):
        print("当前顶点：",cur)
        self.sum+=1
        if(self.sum==self.size):
            return
        for i in range(self.size):
            if self.map[cur][i]==1 and self.flag[i]==0:
                self.flag[i]=1
                self.dfs(i)
            

if __name__=="__main__":
    so=Solution()
    res=so.findCircleNum(isConnected=[[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]])
    print(res)