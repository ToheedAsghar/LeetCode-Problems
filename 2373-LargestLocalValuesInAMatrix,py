from typing import List


class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])

        lgrid = [[0 for _ in range(n-2)] for _ in range(m-2)]

        for i in range(m-2):
            for j in range(n-2):
                tmpMax = max(max(row) for row in [row[j:j+3] for row in grid[i:i+3]])
                lgrid[i][j] = tmpMax

        return lgrid


if __name__ == '__main__':
    grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
    
    sol = Solution()
    print(sol.largestLocal(grid))

