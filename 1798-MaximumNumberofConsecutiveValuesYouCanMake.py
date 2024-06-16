class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        i: int = 0
        currSum: int = 1
        n: int = len(coins)

        coins.sort()

        while i < n and currSum >= coins[i]:
            currSum += coins[i]
            i += 1

        return currSum       
