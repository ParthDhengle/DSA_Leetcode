class Solution:
    def totalCost(self, costs: list[int], k: int, candidates: int) -> int:
        leftpq=[]
        rightpq=[]
        n=len(costs)
        l=0
        r=n-1
        join_at=n-2*candidates
        ans=0
        for i in range(candidates):
            if l<=r:
                leftpq.append(costs[l])
                l+=1
        
        for i in range(candidates):
            if l<=r:
                rightpq.append(costs[r])
                r-=1
        heapq.heapify(leftpq)
        heapq.heapify(rightpq)
        for i in range(k):
            vl = leftpq[0] if leftpq else float('inf')
            vr = rightpq[0] if rightpq else float('inf')
            if vl<=vr:
                ans+=heapq.heappop(leftpq)
                if l<=r:
                    heapq.heappush(leftpq,costs[l])
                    l+=1
            else:
                ans+=heapq.heappop(rightpq)
                if l<=r:
                    heapq.heappush(rightpq,costs[r])
                    r-=1
        return ans