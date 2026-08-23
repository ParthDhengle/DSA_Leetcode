class Solution:
    def reverseVowels(self, s: str) -> str:
        vovels="aeiouAEIOU"
        str_list=list(s)

        l=0
        r=len(s)-1

        while l<r:
            if str_list[l] in vovels and str_list[r] in vovels:
                str_list[l],str_list[r]=str_list[r],str_list[l]
                l+=1
                r-=1
            
            if str_list[l] not in vovels:
                l+=1
            if str_list[r] not in vovels:
                r-=1
                
        return "".join(str_list)