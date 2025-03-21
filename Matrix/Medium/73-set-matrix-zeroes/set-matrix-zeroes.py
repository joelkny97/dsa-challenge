class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)

        cols = len(matrix[0])

        def makeZero(i,j,matrix):
            for x in range(cols):
                print(i,x)
                matrix[i][x] = 0

            for y in range(rows):
                print(y,j)
                matrix[y][j] = 0

        i=0

        mask = []
        while i < rows:
            j=0
            while j < cols:

                if matrix[i][j] == 0:
                    print("Entering set fn",i,j)
                    mask.append((i,j))
                j+=1
            i+=1

        for del_i, del_j in mask:
            makeZero(del_i,del_j,matrix)


        return matrix
            

     
        