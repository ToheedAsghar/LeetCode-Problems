# TC: O(NlogN + KlogK)
# SC: O(N + K)

from typing import List
import heapq

class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        maxProfit: int = 0
        heap: List[] = []
        n: int = len(difficulty)
        i: int = 0

        zipped = sorted(list(zip(difficulty, profit)))
        difficulty, profit = zip(*zipped)
        worker.sort()
        
        for diff in worker:
            while i < n and difficulty[i] <= diff:
                heapq.heappush(heap, -profit[i])
                i += 1
            if heap:
                maxProfit += abs(heap[0])

        return maxProfit

if __name__ == '__main__':
    # difficulty = [68,35,52,47,86]
    # profit = [67,17,1,81,3]
    # worker = [92,10,85,84,82]

    difficulty = [2,4,6,8,10]
    profit = [10,20,30,40,50]
    worker = [4,5,6,7]
    
    difficulty = [13,37,58]
    profit = [4,90,96]
    worker = [34,73,45]

    sol = Solution()
    print(sol.maxProfitAssignment(difficulty, profit, worker)) 
