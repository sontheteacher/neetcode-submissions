class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        min_coin = min(coins)
        if amount == 0:
            return 0
        elif amount < min_coin:
            return -1
        min_change = [None]*(amount + 1)
        min_change[0] = 0
        for i in coins:
            if i < amount + 1:
                min_change[i] = 1
        for j in range(1, min_coin):
            min_change[j] = float("inf")
        
        for i in range(min_coin + 1, amount + 1):
            if min_change[i] is None:
                turn = float("inf")
                for c in coins:
                    if c <= i:
                        turn = min(turn, 1 + min_change[i - c])
                min_change[i] = turn

        if min_change[-1] == float('inf'):
            return -1
        return min_change[-1]