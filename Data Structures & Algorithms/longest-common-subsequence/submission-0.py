class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        memo = [[-1] * (n + 1) for _ in range(m + 1)]

        def dp(i, j):
            if i == 0 or j == 0:
                return 0
            if memo[i][j] > -1:
                return memo[i][j]
            if text1[i - 1] == text2[j - 1]:
                memo[i][j] = 1 + dp(i - 1, j - 1)
            else:
                memo[i][j] = max(dp(i - 1, j), dp(i, j - 1))
            return memo[i][j]
        
        return dp(m, n)
            