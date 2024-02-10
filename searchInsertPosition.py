# Link: https://leetcode.com/problems/search-insert-position/description/
'''
Algorithm:  Binary Search
TC:         O(logn)
SC:         O(1) 
'''

from typing import List
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums)-1

        while(low <= high):
            mid = int(low + (high-low)/2)

            if nums[mid] == target:
                return mid

            if nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return low
    
sol = Solution()
print(sol.searchInsert([1,3,5,6], 7))