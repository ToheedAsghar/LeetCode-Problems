'''
TC:     O(n)
SC:     O(n)
Link:   https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
'''
from typing import List
class Solution:
    # solution 1
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        # two pointer approach
        i,j = (0,1)
        ans = [0] * len(nums)
        for it in nums:
            if(it >= 0):
                ans[i] = it
                i += 2
            else:
                ans[j] = it
                j += 2
        return ans
    # solution 2
    def rearrangeArrayII(self, nums: List[int]) -> List[int]:
        res = []
        i,j = (0,0)
        n = len(nums)
        while(j < n):
            while (nums[i] < 0):
                i += 1
            while (nums[j] >= 0):
                j += 1
            res.append(nums[i])
            res.append(nums[j])
            i += 1
            j += 1
        return res

sol = Solution()
# [3,1,-2,-5,2,-4]
# [-1, 1]
print([-1, 1])