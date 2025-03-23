class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m=len(board)
        n=len(board[0])

        def get_nbs_count(i,j,board):
            nbs_count=0
            for x in range(max(0, i - 1), min(m, i + 2)):
                for y in range(max(0, j - 1), min(n, j + 2)):
                    nbs_count += board[x][y] & 1
            return nbs_count


        for i in range(m):
            for j in range(n):

                ones = get_nbs_count(i,j,board)

                if board[i][j] == 1:
                    if ones == 3 or ones == 4:
                        # bitmasking to show that it was visited and setting next state to dead
                        # bit 0 --> current state of cell, bit 1 --> next state of cell
                        board[i][j] |= 0b10
                    
                if board[i][j] == 0 and ones == 3:
                    # if cell is dead, bitmask to set it alive in next state
                    board[i][j] |= 0b10
                    

                
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1

        # if life:
        #     if nbs_l < 2:
        #         die()
        #     elif nbs_l == 2 or nbs_l == 3:
        #         live()
        #     elif nbs_l > 3:
        #         die()
        # else:
        #     if nbs_d == 3:
        #         live()
        


        