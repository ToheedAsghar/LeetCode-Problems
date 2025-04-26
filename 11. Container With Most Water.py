class Solution:
    def maxArea(self, height: List[int]) -> int:
        n: int = len(height)

        assert( n>= 2, "bounds")

        maxArea: int = 0
        i: int = 0
        j: int = n - 1
        while i < j:
            area: int = (j-i) * min(height[i], height[j])
            maxArea = max(area, maxArea)

            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
            
        return maxArea
