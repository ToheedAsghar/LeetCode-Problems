'''
TC:     O(NlogN)
SC:     O(1)
Link:   https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/
'''
from typing import List
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()                 # O(nlogn)

        # edge case
        n = len(nums)
        perimeter = 0
        # sum of all sides
        for num in nums:            # O(n)
            perimeter += num

        i = n - 1
        while i>=0:                 # O(n)
            if perimeter - nums[i] <= nums[i]:
                perimeter -= nums[i]
                i -= 1
            else:
                break
            
        return -1 if i < 2  else perimeter
        
# [5,5,50]              -> -1 
# [1,12,1,2,5,50,3]     -> 12
# [5,5,5]               -> 15
# [1,5,1,7]             -> -1

sol = Solution()
print(sol.largestPerimeter([1,12,1,2,5,50,3]))