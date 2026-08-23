class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.strip()
        lst=s.split()
        # for i in lst:
        #     if i==" " or i=="":
        #         lst.remove(i)
        lst.reverse()
        return " ".join(lst)