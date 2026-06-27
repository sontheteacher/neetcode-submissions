class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.size = [1] * (n + 1)

    def union(self, x,  y):
        # make x parent of y
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        if self.size[px] >= self.size[py]:
            self.parent[py] = px
            self.size[px] += self.size[py]
        else:
            self.parent[px] = py
            self.size[py] += self.size[px]
        return True

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        rows, cols = len(grid), len(grid[0])
        dsu = DSU(rows * cols)

        def pos(r, c):
            return r  * cols + c
        
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        islands = 0

        for y in range(rows):
            for x in range(cols):
                if grid[y][x] == "1":
                    islands += 1
                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy
                        if (nx < 0 or ny < 0 or nx >= cols or ny >= rows or grid[ny][nx] == "0"):
                            continue
                        
                        if dsu.union(pos(y, x), pos(ny, nx)):
                            islands -= 1
        
        return islands


        
        

        