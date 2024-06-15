from typing import List
import heapq

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n: int = len(capital)
        
        zipped = list(zip(capital, profits))
        zipped = sorted(zipped, key=lambda x:(x[0], -x[1]))
        
        heap = []
        i: int = 0
        
        while k:
            while i < n:
                if w >= zipped[i][0]:
                    heapq.heappush(heap, -zipped[i][1])
                    i += 1
                else:
                    break
            
            if not heap:
                break
        
            w += abs(heapq.heappop(heap))
            k -= 1
            
        return w
            

if __name__ == '__main__':
    sol = Solution()
    
    # k = 2
    # w = 0
    # profits = [1,2,3]
    # capital = [0,1,1]
    
    k = 1
    w = 2
    profits = [1,2,3]
    capital = [1,1,2]
    
    print(sol.findMaximizedCapital(k, w, profits, capital))
