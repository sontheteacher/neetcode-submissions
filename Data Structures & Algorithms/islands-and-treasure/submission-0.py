from copy import deepcopy

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INF = 2**31 - 1
        R, C = len(grid), len(grid[0])
        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]

        starts = set()
        lands = set()
        for i in range(R):
            for j in range(C):
                if grid[i][j] == 0:
                    starts.add((i, j))
                elif grid[i][j] == INF:
                    lands.add((i, j))
        
        time = 1
        while True:
            if len(starts) == 0:
                break
            neis = set()
            while len(starts) > 0:
                r, c = starts.pop()
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if (nr, nc) in lands:
                        neis.add((nr, nc))
                        lands.remove((nr, nc))
            for i, j in neis:
                grid[i][j] = time
            time += 1
            starts = neis
        
