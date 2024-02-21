'''
TC:     O(log(right))
SC:     O(1)
Link:   https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
'''
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        i,j = left, right
        cnt = 0
        
        while i != j:
            i >>= 1
            j >>= 1
            cnt += 1
            
        left >>= cnt
        left <<= cnt   
        return left 
            
'''
Input: left = 5, right = 7
Output: 4

Input: left = 1, right = 2147483647
Output: 0

Input: left = 600000000, right = 2147483645
Output: 
'''

sol = Solution()
print(sol.rangeBitwiseAnd(600000000,2147483645))