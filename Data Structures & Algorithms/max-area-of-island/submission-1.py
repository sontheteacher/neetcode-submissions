class DSU:
    def __init__(self, n):
        self.Parent = list(range(n))
        self.Size = [1] * n

    def find(self, node):
        while self.Parent[node] != node:
            node, self.Parent[node] = self.Parent[node], self.Parent[self.Parent[node]]
        return node
        # if self.Parent[node] != node:
        #     self.Parent[node] = self.find(self.Parent[node])
        # return self.Parent[node]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return
        spx, spy = self.Size[px], self.Size[py]
        if spx >= spy:
            self.Size[px] += spy
            self.Parent[py] = px
        else:
            self.Size[py] += spx
            self.Parent[px] = py
        

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        dsu = DSU(R * C)

        def pos(r, c):
            return r * C + c

        fl = False
        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1:
                    fl = True
                    for dr, dc in directions:
                        nr, nc = i + dr, j + dc
                        if (nr < 0 or nc < 0 or nr >= R or nc >= C or grid[nr][nc] == 0):
                            continue
                        else:
                            dsu.union(pos(i, j), pos(nr, nc))     
        return max(dsu.Size) if fl else 0

                
                

