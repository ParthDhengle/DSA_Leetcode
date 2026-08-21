class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        s=""
        flag=1
        i=0
        j=0
        while i<len(word1) and j<len(word2):
            if flag==1:
                s+=word1[i]
                i+=1
                flag=0
            else:
                s+=word2[j]
                j+=1
                flag=1
        if len(word1)>i:
            s+=word1[i::]
        
        if len(word2)>j:
            s+=word2[j::]
        return s