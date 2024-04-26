from typing import List


class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)

        if 1 == len(grid):
            return grid[0][0]

        dp = [[float('inf') for _ in range(n)] for _ in range(n)]
        
        def dfs(i, j) -> int:
            if i == n-1:
                dp[i][j] = grid[i][j]
                return dp[i][j]
            
            if float('inf') != dp[i][j]:
                return dp[i][j]
            
            val: int = float('inf')
            for k in range(n):
                if j != k:
                    val = min(val, dfs(i+1, k))
            dp[i][j] = grid[i][j] + val
            return dp[i][j]

        for j in range(n):
            for k in range(n):
                if j != k:
                    dp[0][j] = min(dp[0][j], grid[0][j] + dfs(1, k))

        return min(dp[0])


def main() -> None:
    sol = Solution()
    grid = [[-73,61,43,-48,-36], [3,30,27,57,10], [96,-76,84,59,-15], [5,-49,76,31,-7], [97,91,61,-46,67]]
    print(sol.minFallingPathSum(grid))


if __name__ == '__main__':
    main()
