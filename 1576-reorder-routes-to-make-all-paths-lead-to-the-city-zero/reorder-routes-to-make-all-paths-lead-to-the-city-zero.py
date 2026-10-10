from collections import defaultdict

class Solution:
    def minReorder(self, n: int, connections: list[list[int]]) -> int:
        graph=defaultdict(list)
        roads=set()
        for x,y in connections:
            graph[x].append(y)
            graph[y].append(x)
            roads.add((x,y))

        ans=0
        seen=set()
        seen.add(0)
        stack=[]
        stack.append(0)
        while stack:
            city=stack.pop()
            for neigh in graph[city]:
                if neigh in seen:
                    continue
                seen.add(neigh)
                if (city,neigh) in roads:
                    ans+=1
                stack.append(neigh)
        return ans