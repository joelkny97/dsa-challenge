class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows>=len(s):
            return s
            
        res = [[] for _ in range(numRows)]
        idx=0
        direction=1 # 1 for down and -1 for up

        i=0

        for c in s:
            res[idx].append(c)

            if idx==0:
                direction=1
            elif idx == numRows-1:
                direction=-1
            
            idx+= direction

        for i in range(numRows):
            res[i] = ''.join(res[i])

    
        return "".join(res)


        