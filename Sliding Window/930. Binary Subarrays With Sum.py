# TC: O(N)

class Solution:
    def slidingWindowAtMost(self, nums: List[int], goal: int) -> int:
        i: int = 0
        currSum: int = 0
        totalArrays: int = 0

        for j in range(len(nums)):
            currSum += nums[j]

            while i <= j and currSum > goal:
                currSum -= nums[i]
                i += 1
            
            totalArrays += (j - i + 1)
        
        return totalArrays

    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        return self.slidingWindowAtMost(nums, goal) - self.slidingWindowAtMost(nums, goal-1)
