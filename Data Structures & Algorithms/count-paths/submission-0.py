class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        fact = lambda x: math.factorial(x)
        return int(fact(m + n - 2)/(fact(m - 1)*fact(n - 1)))