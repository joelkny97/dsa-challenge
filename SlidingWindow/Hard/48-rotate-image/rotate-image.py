
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # joel
        # m = len(matrix)
        # n = len(matrix[0])

        # # s = deque()
        # # vertical trasnform

        # swap_idx = n-1
        # for i in range(m):
        #     if swap_idx < 0:
        #         break
        #     for j in range(n):
        #         # if swap_idx == j:
        #         #     break

        #         temp = matrix[i][j]
        #         matrix[i][j] = matrix[swap_idx][j]
        #         matrix[swap_idx][j] = temp
        #         # print(matrix[i][j])

        #     swap_idx -= 1
            

        # # print(matrix)

        # for i in range(m):
        #     for j in range(n):
        #         temp = matrix[i][j]
        #         matrix[i][j] = matrix[j][i]
        #         matrix[j][i]  = temp

        #         # print(matrix[i][j])

        edge_length = len(matrix)

        top = 0
        bottom = edge_length - 1

        while top < bottom:
            for col in range(edge_length):
                temp = matrix[top][col]
                matrix[top][col] = matrix[bottom][col]
                matrix[bottom][col] = temp
            top += 1
            bottom -= 1

        for row in range(edge_length):
            for col in range(row+1, edge_length):
                temp = matrix[row][col]
                matrix[row][col] = matrix[col][row]
                matrix[col][row] = temp


        return matrix

        




        