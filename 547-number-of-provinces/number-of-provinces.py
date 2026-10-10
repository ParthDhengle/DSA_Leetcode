class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n=len(isConnected)
        visited=[0]*n
        ans=0
        for i in range(n):
            if visited[i]:
                continue
            st=[]
            st.append(i)
            while st:
                city=st.pop()
                if visited[city]:
                    continue
                visited[city]=1
                for j in range(n):
                    if isConnected[city][j] and not visited[j]:
                        st.append(j)
            ans+=1

        return ans