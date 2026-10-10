class Solution:
    def canVisitAllRooms(self, rooms: list[list[int]]) -> bool:
        n=len(rooms)
        c=1
        st=[]
        st.extend(rooms[0])
        visited=[0]*n
        visited[0]=1
        while st:
            key=st.pop()
            if visited[key]:
                continue
            visited[key]=1
            c+=1
            st.extend(rooms[key])

        return c==n
