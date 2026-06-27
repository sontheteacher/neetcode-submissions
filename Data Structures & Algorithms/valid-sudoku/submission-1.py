class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        squares3x3 = [[[], [], []], [[], [], []], [[], [], []]]

        for i in range(0, 9):
            row = board[i]
            col = [board[j][i] for j in range(9)]
            print(row, col)

            # Check current row for duplicates, along with 
            # constructing the 3x3 squares
            curr_r = []
            for j in range(9):
                if row[j] == ".":
                    continue
                curr_r.append(row[j])
                if j >= i:
                    squares3x3[i // 3][j // 3].append(row[j])
            if len(set(curr_r)) != len(curr_r):
                return False
            
            # Check current col for duplicates
            # along with constructing 3x3 squares
            curr_c = []
            for j in range(9):
                if col[j] == ".":
                    continue
                curr_c.append(col[j])
                if j > i:
                    squares3x3[j // 3][i // 3].append(col[j])
            if len(set(curr_c)) != len(curr_c):
                return False
        
        # Check squares for duplicate
        for level in squares3x3:
            for sq in level:
                if len(set(sq)) != len(sq):
                    return False
        return True