from typing import List
from collections import Counter

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n: int = len(hand)
        
        if n%groupSize != 0:
            return False

        res: bool = True
        i: int = 0

        hm = Counter(hand)
        keys = sorted(list(set(hand)))
    
        while res and i < len(keys):            
            j: int = i + 1
            k: int = groupSize - 1
            flag: bool = False
            
            while res and j < len(keys) and k > 0:
                if keys[j] != keys[j-1]+1 or hm[keys[j]] < hm[keys[i]]:
                    res = False
                    
                if not flag and hm[keys[j]] > hm[keys[i]] and 1 == hm[keys[i]]:
                    hm[keys[i]] -= 1
                    i = j
                    flag = True
                    
                k -= 1
                hm[keys[j]] -= 1                    
                j += 1
            
            if k:
                res = False
                
            
            if not flag:
                hm[keys[i]] -= 1
                if 0 == hm[keys[i]]:
                    i += groupSize

        return res

if __name__ == '__main__':
    sol = Solution()
    
    hand = [1, 2, 3, 6, 2, 3, 4, 7, 8]
    groupSize = 3
    
    
    # hand = [1, 2, 3]
    # groupSize = 1
    
    # hand = [1,1,2,2,3,3]
    # groupSize = 2
    
    # hand = [8, 8, 9, 7, 7, 7, 6, 7, 10, 6]
    # groupSize = 2
    
    print(sol.isNStraightHand(hand, groupSize))
  
