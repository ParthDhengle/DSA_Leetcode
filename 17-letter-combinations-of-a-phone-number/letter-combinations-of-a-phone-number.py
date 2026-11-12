class Solution:
    def rec(self,digits,curr, lst,buttons, s):
        if curr>=len(digits):
            lst.append(s)
            return
        for char in buttons[int(digits[curr])-2]:
            new_s=s+char
            self.rec(digits,curr+1,lst,buttons,new_s)

    def letterCombinations(self, digits: str) -> list[str]:
        lst=[]
        buttons=['abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
        self.rec(digits, 0,lst,buttons,"")
        return lst