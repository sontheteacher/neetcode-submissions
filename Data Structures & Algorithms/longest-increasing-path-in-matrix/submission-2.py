class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        ROW, COL = len(matrix), len(matrix[0])
        dp = [[-1] * COL for _ in range(ROW)]
        res = 1
        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]

        def dfs(r, c):
            if dp[r][c] > -1:
                return dp[r][c]
            temp = []
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if nr < 0 or nc < 0 or nr >= ROW or nc >= COL or matrix[nr][nc] >= matrix[r][c] :
                    continue
                temp.append(dfs(nr, nc))
            if not temp:
                dp[r][c] = 1
            else:
                dp[r][c] = max(temp) + 1
            return dp[r][c]
        
        mv = min(min(row) for row in matrix)
        for r in range(ROW):
            for c in range(COL):
                if matrix[r][c] == mv:
                    dp[r][c] = 1

        for r in range(ROW):
            for c in range(COL):
                if dp[r][c] == -1:
                    dfs(r, c)
                res = max(dp[r][c], res)
        return res
                