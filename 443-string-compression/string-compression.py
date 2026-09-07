class Solution:
    def compress(self, chars: List[str]) -> int:
        n=len(chars)
        if n==0:
            return 0
        ans=1
        count=1
        k=0
        for i in range(1,n):
            if chars[i-1]==chars[i]:
                count+=1
            else:
                chars[k]=chars[i-1]
                k+=1
                if(count>1):
                    char_count=str(count)
                    for i in char_count:
                        chars[k]=i
                        k+=1
                    count=1

        chars[k]=chars[n-1]
        k+=1
        if(count>1):
            char_count=str(count)
            for i in char_count:
                chars[k]=i
                k+=1
        return k