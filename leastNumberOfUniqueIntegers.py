'''
TC:     O(NlogN)
SC:     O(N)
Link:   https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/ 
'''
from typing import List
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        dict = {}
        for num in arr:
            dict[num] = dict.get(num, 0) + 1

        # second dictionary - sorted hashmap
        hm = sorted(dict.items(), key=lambda x: x[1])

        for key,value in hm:
            if value <= k:
                k -= value
                del dict[key]
            else:
                break;

        return len(dict)

sol = Solution()
# arr = [4,3,1,1,3,3,2], k = 3
# arr = [5,5,4], k = 1
print(sol.findLeastNumOfUniqueInts([5,5,4], 1))