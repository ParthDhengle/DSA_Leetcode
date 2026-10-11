from collections import defaultdict
class Solution:
    def dfs(self, node,dest,gr, visited,a,temp):
        if node in visited:
            return
        visited.add(node)
        if node== dest:
            a[0]=temp

        for neigh in gr[node]:
            if neigh not in visited:
                self.dfs(neigh, dest,gr,visited,a,temp*gr[node][neigh])

    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        gr=defaultdict()
        n=len(equations)
        for i in range(n):
            dividend=equations[i][0]
            divisor=equations[i][1]
            value=values[i]

            if not dividend in gr:
                gr[dividend]={}
            if not divisor in gr:
                gr[divisor]={}

            gr[dividend][divisor]=value
            gr[divisor][dividend]=1.0/value

        
        ans=[]
        for q in queries:
            dividend=q[0]
            divisor=q[1]
            if dividend not in gr or divisor not in gr:
                ans.append(-1.0)
            else :
                visited=set()
                a=[-1.0]
                temp=1
                self.dfs(dividend,divisor,gr,visited,a,temp)
                ans.append(a[0])

        return ans