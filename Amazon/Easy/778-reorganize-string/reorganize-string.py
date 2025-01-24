
from collections import Counter
import heapq

class Solution:
    def reorganizeString(self, s: str) -> str:
        char_freq = Counter(s)

        max_heap = []
        for i,j in char_freq.items():
            max_heap.append( (-j, i) )

        heapq.heapify(max_heap)

        res = [] # empty result
        prev_freq, prev_char = 0,""

        while max_heap:
            freq,char = heapq.heappop(max_heap)
            res.append(char)

            if prev_freq < 0:
                heapq.heappush(max_heap, (prev_freq,prev_char) )
            
            freq+=1
            prev_freq, prev_char = freq,char

        if len(res) != len(s):
            return ""
        
        return "".join(res)


        
        
