class Solution:
    def longestPalindrome(self, s: str) -> int:
        dict = Counter(s)
        
        even: int = 0
        odd: int = 0
        flag: int = False

        for val in dict.values():
            if 0 == val%2:
                even += val

            if 0 != val%2:
                flag = True
                odd += (val - 1)

        return even+odd+1 if flag else even+odd
                
