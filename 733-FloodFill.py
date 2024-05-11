from collections import deque
from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
      # edge case
        if image[sr][sc] == color:
            return image
        
        m = len(image)
        n = len(image[0])

        queue = deque()
        queue.append([sr, sc])
        currColor = image[sr][sc]

        r = [-1, 0, 0 , 1]
        c = [0, -1, 1, 0]

        while queue:
            dim = queue.popleft()
            row, col = dim[0], dim[1]
            image[row][col] = color
            for i in range(4):
                if row + r[i] >= 0 and row + r[i] < m and col + c[i] >= 0 and col + c[i] < n:
                    if image[row+r[i]][col+c[i]] == currColor:
                        queue.append([row+r[i], col+c[i]])

        return image
            
    
if __name__ == '__main__':
    image = [[1,1,1],[1,1,0],[1,0,1]]
    sr = 1
    sc = 1
    color = 2
    
    sol = Solution()
    print(sol.floodFill(image, sr, sc, color))
  
