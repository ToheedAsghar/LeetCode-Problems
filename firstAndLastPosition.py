from typing import List
'''
Link:   https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
TC:     O(log N)
SC:     O(1)
'''
class Solution:
    def leftSearch(self, nums, target):
        i = 0
        j = len(nums) - 1
        while i < j:
            mid = (j + i) // 2
            if nums[mid] < target:
                i = mid + 1
            else:
                j = mid
        return i
    def rightSearch(self, nums, target):
        i = 0
        j = len(nums) - 1
        while i < j:
            mid = (j + i) // 2
            if nums[mid] <= target:
                i = mid + 1
            else:
                j = mid
        return i
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = self.leftSearch(nums, target)
        right = -1
        if left < len(nums) and nums[left] == target:
            right = self.rightSearch(nums, target)
            if right < len(nums) and nums[right] == target:
                return [left, right]
            else:
                return [left, right-1]
        else:
            return [-1, -1]
        
sol = Solution()
print(sol.searchRange([5,7,7,8,8,10], 8))