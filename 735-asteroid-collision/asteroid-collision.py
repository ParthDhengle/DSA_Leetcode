class Solution:
    def asteroidCollision(self, asteroids: list[int]) -> list[int]:
        ans=[]
        for i in asteroids:
            while ans and ans[-1]>0 and i<0:
                last=ans[-1]
                if last == abs(i):
                    ans.pop()
                    break
                elif last < abs(i):
                    ans.pop()
                else:
                    break
            else:
                ans.append(i)
        return ans