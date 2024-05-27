# [1608 - Special Array With X Elements Greater Than or Equal X](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/)

## Naive Algorithm (Brute Force)

**TC:** O(n<sup>2</sup>)

```python
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n: int = len(nums)
        for x in range(0, n+1):
            cnt: int = 0
            for num in nums:
                if num >= x:
                    cnt += 1
                if cnt > x:
                    cnt = -1
                    break
            if cnt == x:
                return cnt
        return -1
```

## Efficient Algorithm

**TC**: O(2nlogn) → O(nlogn)

```python
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        if nums[0] >= n:
            return n
        for i in range(1, n+1):
            index = bisect.bisect_left(nums, i)
            if index == n - i:
                return i
            
        return -1
```

![image](https://github.com/ToheedAsghar/LeetCode-Problems/assets/121859513/6fd993a6-8cc0-4ad8-8502-9f11869339fa)
