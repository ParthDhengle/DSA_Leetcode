class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        queue=deque()
        ans=0
        fresh=0
        for i in range(n):
            for j in range(m):
                if grid[i][j]==2:
                    queue.append((i,j))
                if grid[i][j]==1:
                    fresh+=1
        if fresh==0:
            return 0
        count=len(queue)
        dir=[-1,0,1,0,-1]
        index=0
        while(queue) and fresh>0:
            quelen=len(queue)
            for i in range(quelen):
                x,y=queue.popleft()
                for i in range(4):
                    nx=x+dir[i]
                    ny=y+dir[i+1]
                    if 0<=nx<n and 0<=ny<m and grid[nx][ny]==1:
                        queue.append((nx,ny))
                        grid[nx][ny]=2
                        fresh-=1
            ans+=1
        if fresh==0:
            return ans
        return -1



            

                

        