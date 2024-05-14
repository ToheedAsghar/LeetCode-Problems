from typing import List

class Solution:
    def getMaximumGold(self, grid:List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        
        def dfs(i, j, path):
            if 0 == grid[i][j]:
                return 0
            
            row = [-1, 0, 1, 0]
            col = [0, 1, 0, -1]
            
            maxValue = grid[i][j]
            for k in range(4):
                if i+row[k] >= 0 and i + row[k] < n and j + col[k] >= 0 and j + col[k] < m:
                    if (i+row[k], j+col[k]) not in path:
                        path.add((i+row[k], j + col[k]))
                        maxValue = max(maxValue, grid[i][j] + dfs(i+row[k], j + col[k], path))
                        path.remove((i+row[k], j+col[k]))
            
            return maxValue
                
        maxGold = 0
        Gold = []  
        for i in range(n):
            for j in range(m):
                path = set()
                path.add((i, j))
                maxGold = max(maxGold, dfs(i, j, path))
 
        return maxGold
        
        
def main() -> None:
    # grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]         # 28
    # grid = [[0,6,0],[5,8,7],[0,9,0]]                          # 24
    grid = [[1,6,1],[5,8,7],[1,9,1]]                          # 39
    
    sol = Solution()
    print(sol.getMaximumGold(grid))
    
    
if __name__ == '__main__':
    main()
