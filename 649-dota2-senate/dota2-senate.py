class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        r=deque()
        d=deque()
        for i,sen in enumerate(senate):
            if sen == "R":
                r.append(i)
            else:
                d.append(i)
        
        n=len(senate)
        while r and d:
            ri=r.popleft()
            di=d.popleft()
            if ri < di:
                r.append(ri+n)
            else:
                d.append(di+n)
        if d:
            return "Dire"
        return "Radiant"