# [881 - Boats to Save People](https://leetcode.com/problems/boats-to-save-people/description/)

## Python Code

```python

from typing import List

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        i: int = 0
        j: int = len(people) - 1
        cnt: int = 0

        while j >= i:
            if j == i:
                cnt += 1
                break

            if people[i] + people[j] <= limit:
                i += 1
            
            j -= 1
            cnt += 1
        
        return cnt
    
if __name__ == '__main__':
    sol = Solution()
    people = [1, 1, 2, 2]
    limit = 3
    print(sol.numRescueBoats(people, limit))

```

## TC and SC:

**TC**: O(nlogn + n)

**SC**: O(1)
