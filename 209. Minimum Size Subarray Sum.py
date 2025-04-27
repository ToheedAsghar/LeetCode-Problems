# from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i: int = 0
        j: int = 0
        n: int = len(nums)
        ml: int = float('inf') # worst case
        arraySum: int = 0

        while j < n:
            arraySum += nums[j]
            if arraySum >= target:
                while i < j and arraySum > target and arraySum - nums[i] >= target:
                    arraySum -= nums[i]
                    i += 1
                ml = min(ml, j - i + 1)
            j += 1

        return ml if ml != float('inf') else 0

# def main() -> None:
#     # target = 7
#     # nums = [2,3,1,2,4,3]

#     target = 11
#     nums = [1,1,1,1,1,1,1,1]
    
#     sol = Solution()
#     print(sol.minSubArrayLen(target, nums))

# if __name__ == '__main__':

#     main()
