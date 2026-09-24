class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        freq={}
        for i in arr:
            freq[i]= freq.get(i,0) +1

        if len(freq.values()) == len(set(freq.values())):
            return True
        return False