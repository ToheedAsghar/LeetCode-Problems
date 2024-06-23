"""
TC: O(N)
SC: O(N)
"""

from typing import List
from collections import defaultdict

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        countMap: dict = defaultdict(int)
        
        # default value for zero
        countMap[0] = -1

        n: int = len(nums)
        maxLength: int = 0
        count: int = 0

        for i in range(n):
            count += (-1 if 0 == nums[i] else 1)

            if count in countMap:
                maxLength = max(maxLength, i - countMap[count])
            else:
                countMap[count] = i
        
        return maxLength



if __name__ == '__main__':
    sol = Solution()

    nums: List[int] = [0, 1, 0, 0, 1, 1, 0]
    print(sol.findMaxLength(nums))
