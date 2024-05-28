class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        i: int = 0
        j: int = 0
        n: int = len(s)
        maxLen: int = 0
        currLen: int = 0
        currCost: int = maxCost

        while j < n:
            diff = abs(ord(s[j]) - ord(t[j]))
            if diff > currCost:
                while i <= j:
                    tmp = abs(ord(s[i]) - ord(t[i]))
                    currCost += tmp
                    currLen -= 1
                    i += 1
                    if diff <= currCost:
                        break
            
            currLen += 1
            maxLen = max(maxLen, currLen)
            currCost -= diff

            j += 1

        return maxLen
    
if __name__ == '__main__':
    # s = "abcd"
    # t = "bcdf"
    # maxCost = 3

    # s = "abcd"
    # t = "cdef"
    # maxCost = 3

    s = "abcd"
    t = "acde"
    maxCost = 0

    sol = Solution()
    print(sol.equalSubstring(s, t, maxCost))
    
