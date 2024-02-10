# Link: minCostClimbingStairs
'''
TC: O(n)
SC: O(1) as we are updating the original array
'''
from typing import List
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        i = n - 2
        cost.append(0)

        while i >= 0:
            cost[i] += min(cost[i+1], cost[i+2])
            i -= 1
            
        return min(cost[0], cost[1])

sol = Solution()
cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
print(sol.minCostClimbingStairs(cost))

# [10, 15, 20] -> 15
# [1, 100, 1, 1, 1, 100, 1, 1, 100, 1] -> 6