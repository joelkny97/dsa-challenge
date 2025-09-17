class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        
        n = len(grid)
        a=-1
        b=-1
        hashmap = {i:0 for i in range(1,n**2 + 1)}

        for i in grid:
            for j in i:
                if hashmap.get(j) == 0:
                    hashmap[j]+=1

                else:
                    hashmap[j] +=1
                    a = j
        
        for i in hashmap:
            if hashmap[i]==0:
                return [a, i]

        return [a,b]

            

