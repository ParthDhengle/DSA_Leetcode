class MinStack:
    

    def __init__(self):
        self.lst=[]
        self.min=[]

    def push(self, value: int) -> None:
        self.lst.append(value)
        if not self.min or self.min[-1]>=value:
            self.min.append(value)

    def pop(self) -> None:
        if self.lst[-1]==self.min[-1]:
            self.min.pop()
        self.lst.pop()

    def top(self) -> int:
        return self.lst[-1]

    def getMin(self) -> int:
        return self.min[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()