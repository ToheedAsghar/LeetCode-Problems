class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        i: int = 0
        j: int = 0
        n: int = len(s)
        m: int = len(t)

        while i < n and j < m:
            if s[i] == t[j]:
                j += 1
            i += 1
        return m - j
