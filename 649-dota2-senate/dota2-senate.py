class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        r=0
        d=0
        for i in senate:
            if i == "R":
                r+=1
            else:
                d+=1
        i=0
        n=len(senate)
        lst=list(senate)

        while r>0 and d>0:
            if lst[i]=="D":
                j=(i+1)%n
                while lst[j]!="R":
                    j=(j+1)%n
                lst[j]="O"
                r-=1
            if lst[i]=="R":
                j=(i+1)%n
                while lst[j]!="D":
                    j=(j+1)%n
                lst[j]="O"
                d-=1
            i=(i+1)%n
        if r==0:
            return "Dire"
        return "Radiant"