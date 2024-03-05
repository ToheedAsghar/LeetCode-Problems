'''
Link:   https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
'''
from collections import deque
class Solution:
    # TC: O(n) and SC: O(1)
    def minimumLength(self, s: str) -> int:
        i: int = 0
        n = len(s)
        j: int = n - 1

        while i < j and s[i] == s[j]:
            ch: char = s[i]
            while i <= j and s[i] == ch:
                i += 1
            while i <= j and s[j] == ch:
                j -= 1

        return j - i + 1
    # TC: O(n) and SC: O(n)
    def minimumLengthI(self, s: str) -> int:
        deq = deque(s)
        n: int = len(s)
        i: int = 0
        j: int = n - 1
        ic(len(deq))
        while(len(deq) > 1 and deq[0] == deq[len(deq)-1]):
            x = deq[0]
            while 0 != len(deq) and deq[0] == x:
                deq.popleft()
            while 0 != len(deq) and deq[-1] == x:
                deq.pop()
                
        return len(deq)

# bbacaabb
# aabccabba

def main() -> None:
    sol = Solution()
    print(sol.minimumLength("ca"))
    
    
if __name__ == '__main__':
    main()