class Solution:
    def equalPairs(self, grid: list[list[int]]) -> int:
        n=len(grid)
        col_grid=[]
        for i in range(n):
            row=[]
            col=[]
            for j in range(n):
                col.append(grid[j][i])
            col_grid.append(col)
        ans=0
        idx=[]
        for i in range(n):
            if grid[i] in col_grid:
                for ele in col_grid:
                    if ele ==grid[i]:
                        ans+=1
        return ans
        

        