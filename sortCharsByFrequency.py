# https://leetcode.com/problems/sort-characters-by-frequency/description/

from collections import defaultdict
'''
TC: O(nlogn)
SC: O(1)
'''
class Solution:
    def frequencySort(self, s: str) -> str:
        dict = defaultdict(int)
        # O(n)
        for it in s:
            dict[it] = dict[it] + 1
        
        # O(n)
        list = []
        for key,value in dict.items():
            list.append((value, key))
        
        # O(nlogn)
        list = sorted(list, key=lambda x:x[0], reverse=True)
        
        ret = ""
        for it in list:
            n = it[0]
            while n != 0:
                ret += it[1]
                n -= 1
        return ret
        

sol = Solution()
print(sol.frequencySort("tree"))

# aaaccc
# tree
# Aabb

