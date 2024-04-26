# [2370 - Longest Ideal Subsequence](https://leetcode.com/problems/longest-ideal-subsequence/description/)

### [Subsequence](https://math.stackexchange.com/questions/2442042/what-is-a-subsequence-in-calculus) 

In mathematics, a subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

## Problem Analysis

We are given a string of atmost 10<sup>5</sup> characters. We've to find the longest subsequence and the property of the resultant subsequence should be that the absolute difference between consecutive elements must be less than or equal to integer *k*.

## Naive Solution

**TC: O(n<sup>2</sup>)**

```python3

class Solution:
    def dp(self, memo, i, s, k) -> int:
        if i >= len(s):
            return 0

        if -1 != memo[i]:
            return memo[i]
        
        val: int = 1
        n = len(s)
        for j in range(i+1, n):
            if abs(ord(s[i])-ord(s[j])) <= k:
                val = max(val, 1 + self.dp(memo, j, s, k))
        
        memo[i] = val
        return memo[i]
        
    def longestIdealString(self, s: str, k: int) -> int:

        n = len(s)
        memo = [-1] * n
        
        for i in range(n):
            memo[i] = self.dp(memo, i, s, k)
        
        return max(memo)

```

## More Efficient Solution

```python3

class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        dp = [0] * 26
        for c in s:
            currIndex = ord(c) - ord('a')
            l = 1
            for i in range(currIndex - k, currIndex + k + 1):
                if i >= 0 and i < 26:
                    l = max(l, 1 + dp[i])
            dp[currIndex] = l
        return max(dp)

def main() -> None:
    sol = Solution()
    s = 'dll'
    k = 0
    print(sol.longestIdealString(s, k))

if __name__ == "__main__":
    main()

```

## Time Complexity

The time complexity of the longestIdealString function is **O(n * k)**, where n is the length of the input string s and k is the given integer.

## Space Complexity

The space complexity of the longestIdealString function is **O(1)**, as it uses a fixed-size array dp of length 26 (the number of lowercase letters in the English alphabet).

## Result

![image](https://github.com/ToheedAsghar/LeetCode-Problems/assets/121859513/c20fd333-af88-4423-b4ba-d2694a460be0)
