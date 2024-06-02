# [1332. Remove Palindromic Subsequences](https://leetcode.com/problems/remove-palindromic-subsequences/description/) 

The Problem can be tricky if the word **subsequence** was replaced with **substring**. The concept is simple, The max answer can be ***2*** and the min answer can be ***1***:
- The answer will be min if the entire string is palindrome. In such case, we can remove the palindromic subsequence in one step.
- The answr will be max if the string is not palindrome. In one step, we will remove all the a's as the palindrome which will consists of only a's. In the second step, we'll remove all the b's i.e. the palindromic subsequence consisting of only b's.

```python
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if s == s[::-1]:
            return 1
        else:
            return 2
        
```

## Time Complexity and Space Complexity:

The time complexity will be **O(n)** on checking if the string is palindrome or not. Thus the worst case and best case time complexity is order of n where n is the length of the string. The algorithm uses Constant Space that is O(1).

![image](https://github.com/ToheedAsghar/LeetCode-Problems/assets/121859513/0181147b-c0bb-4cc6-b8b5-dcf04e396ff6)
