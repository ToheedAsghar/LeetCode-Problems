# [139. Word Break](https://leetcode.com/problems/word-break/description/)

## Recursion Solution with Memoization

```python
from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [-1] * (n+1)
        
        def wordBreakDp(i):
            if i == n:
                dp[i] = 1
            elif -1 == dp[i]:
                for word in wordDict:
                    if i + len(word) <= n and s[i: i+len(word)] == word:
                        dp[i] = wordBreakDp(i + len(word))
                    if 1 == dp[i]:
                        break
                if -1 == dp[i]:
                    dp[i] = 0
                    
            return dp[i]
        
        dp[0] = wordBreakDp(0)
        return True if dp[0] else False
                    
        
def main() -> None:
    sol = Solution()
    s = 'leetcode'
    wordDict = ['leet', 'code']
    
    print(sol.wordBreak(s, wordDict))
    
if __name__ == "__main__":
    main()
```

## Results

![image](https://github.com/ToheedAsghar/LeetCode-Problems/assets/121859513/2f169b67-0ae6-474c-a9e9-0c49a27a3e3a)

## Dynamic Programming Solution

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n+1)
        dp[n] = True

        for i in range(n-1, -1, -1):
            for word in wordDict:
                if i + len(word) <= n and s[i : i + len(word)] == word:
                    dp[i] = dp[i + len(word)]
                
                if dp[i]:
                    break

        return dp[0]

if __name__ == '__main__':
    sol = Solution()
    s = 'catsandog'
    wordDict = ['cats', 'dog', 'sand', 'and', 'cat']
    print(sol.wordBreak(s, wordDict))

```

## Results of DP

![image](https://github.com/ToheedAsghar/LeetCode-Problems/assets/121859513/e94417fc-9fbc-458e-99d0-893f7ced9ee1)
