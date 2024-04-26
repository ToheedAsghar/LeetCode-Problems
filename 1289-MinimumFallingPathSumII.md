# [1289. Minimum Falling Path Sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii/description/)

## Python Code

```python3

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
```

## Time Complexity

- The code uses dynamic programming with memoization (top-down approach).
- The function dfs(i, j) is called recursively for each cell in the grid, with each cell being visited only once. Within the function, there's a loop that iterates over all cells in the next row (i+1), resulting in a time complexity of O(n^2), where n is the size of the grid.
- The nested loop in the minFallingPathSum function iterates over each cell in the first row of the grid, resulting in another O(n^2) operations.
- So, the time complexity is **O(n^2)**.

## Space Complexity:

- The space complexity mainly comes from the dynamic programming table dp, which is initialized as an n x n matrix, where n is the size of the grid. So, the space complexity of the dp matrix is O(n^2).
- Additionally, there's the recursive stack space used by the dfs function. Since the function is called recursively for each cell in the grid, the maximum depth of recursion can be n, corresponding to the height of the grid. So, the space complexity due to recursion is O(n).
- Therefore, the space complexity is **O(n^2)**.

