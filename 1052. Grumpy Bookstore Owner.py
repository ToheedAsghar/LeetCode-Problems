"""
TC: O(N)
SC: O(1)
"""

from typing import List


class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        runningSum: int = 0
        i: int = 0
        j: int = 0
        temp: int = minutes
        while temp:
            runningSum += customers[j]
            temp -= 1
            j += 1

        maxSum = runningSum
        n: int = len(customers)
        while j < n:
            while grumpy[j] and (j - i) > minutes - 1:
                if grumpy[i]:
                    runningSum -= customers[i]
                i += 1
            runningSum += customers[j]
            if not grumpy[j]:
                maxSum += customers[j]
            maxSum = max(maxSum, runningSum)
            j += 1

        return maxSum


if __name__ == '__main__':
    customers = [1, 0, 1, 2, 1, 1, 7, 5]
    grumpy = [0, 1, 0, 1, 0, 1, 0, 1]
    minutes = 3

    customers = [1]
    grumpy = [0]
    minutes = 1

    customers = [1, 2, 1, 1, 1, 3]
    grumpy = [1, 1, 1, 0, 0, 1]
    minutes = 3

    customers = [2,4,1,4,1]
    grumpy = [1,0,1,0,1]
    minutes = 2

    # customers =  [9, 10, 4, 5]
    # grumpy =  [1, 0, 1, 1]
    # minutes = 1

    sol = Solution()
    print(sol.maxSatisfied(customers, grumpy, minutes))
