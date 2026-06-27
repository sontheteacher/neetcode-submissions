class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
       cols = defaultdict(set)
       rows = defaultdict(set)
       squares = defaultdict(set)
       for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == ".":
                    continue
                square_index = (r // 3) * 3 + (c // 3)
                if val in rows[r] or val in cols[c] or val in squares[square_index]:
                    return False
                rows[r].add(val)
                cols[c].add(val)
                squares[square_index].add(val)
       return True