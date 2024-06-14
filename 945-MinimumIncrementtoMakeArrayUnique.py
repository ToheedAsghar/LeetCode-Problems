class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        steps: int = 0
        nums.sort()
        n = len(nums)

        curr: int = nums[0]

        for i in range(n-1):
            if curr >= nums[i+1]:
                curr += 1
                steps += (curr - nums[i+1])
            else:
                curr = nums[i+1]
        
        return steps
