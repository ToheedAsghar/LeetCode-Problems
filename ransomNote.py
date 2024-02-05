# https://leetcode.com/problems/ransom-note/description/

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        n = len(ransomNote)
        m = len(magazine)

        if n > m: return False

        hm = {}

        for ch in magazine:
            hm[ch] = hm.get(ch, 0) + 1
        
        for ch in ransomNote:
            if ch in hm and hm[ch] > 0:
                hm[ch] -= 1
            else:
                return False
        return True

sol = Solution()
print(sol.canConstruct("aa", "aab"))