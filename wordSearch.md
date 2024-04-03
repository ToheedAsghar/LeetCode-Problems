# [79. Word Search](https://leetcode.com/problems/word-search/description/)

## Time Complexity

The time complexity of the exist function is O(n*m*3^k), where n and m are the dimensions of the board and k is the length of the word. The function iterates over each cell of the board, and for each cell, it recursively calls the dfs function for all neighboring cells that match the next character of the word. The worst-case time complexity occurs when the word can be formed by visiting all neighboring cells at each step, leading to a time complexity of O(3^k) for each cell. Therefore, the overall time complexity is **O(n*m*3^k)**.

## Space Complexity

The space complexity of the exist function is O(n*m) due to the creation of the flags matrix of size n*m. The recursive calls of the dfs function do not contribute to the space complexity as they are executed on the same call stack. Therefore, the space complexity is **O(n*m)**.

```python

from typing import List

class Solution:
    def dfs(self, board, word, flags, k, i, j):
        n = len(board)
        m = len(board[0])
        
        if k == len(word)-1:
            return True
        
        s1, s2, s3, s4 = False, False, False, False
        
        if j-1 >= 0 and 0 == flags[i][j-1] and board[i][j-1] == word[k+1]:
            flags[i][j-1] = 1;
            s1 = self.dfs(board, word, flags, k+1, i, j-1)
            flags[i][j-1] = 0
        
        if i-1 >= 0 and 0 == flags[i-1][j] and board[i-1][j] == word[k+1]:
            flags[i-1][j] = 1;
            s2 = self.dfs(board, word, flags, k+1, i-1, j)
            flags[i-1][j] = 0;
            
        if i+1 < n and 0 == flags[i+1][j] and board[i+1][j] == word[k+1]:
            flags[i+1][j] = 1;
            s3 = self.dfs(board, word, flags, k+1, i+1, j)
            flags[i+1][j] = 0;
            
        if j+1 < m and 0 == flags[i][j+1] and board[i][j+1] == word[k+1]:
            flags[i][j+1] = 1;
            s4 = self.dfs(board, word, flags, k+1, i, j+1)
            flags[i][j+1] = 0;
            
        return s1 or s2 or s3 or s4
    

    def exist(self, board: List[List[str]], word: str) -> bool:
        
        n = len(board)
        m = len(board[0])
        k = 0
        flags = [[0 for _ in range(m)] for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                if word[k] == board[i][j]:
                    flags[i][j] = 1
                    status = self.dfs(board, word, flags, k, i, j)
                    flags[i][j] = 0
                    
                    if status:
                        return True
                    
        return False

    
def main():
    sol = Solution()
    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]] 
    word = "SEE"
    
    print(sol.exist(board, word=word))
    
    
if __name__ == "__main__":
    main()

```

## Test Cases
```python
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]] "ABCCED"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]] "ABCB"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]] "SEE" 
```
