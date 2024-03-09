# Link: https://leetcode.com/problems/minimum-common-value/description/
import bisect
from typing import List
   
class Solution:
    # TC:   O(nlogn)
    # SC:   O(1)
    def binary_search_bisect(arr, x):
        i = bisect.bisect_left(arr, x)
        if i != len(arr) and arr[i] == x:
            return i
        else:
            return -1
    def getCommonII(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        
        for i in range(n):
            index = self.binary_search_bisect(nums2, nums1[i])
            if -1 != index:
                return nums2[index]
        return -1
       
    # TC: O(n) SC: O(1) 
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:        
        # two pointer approach
        i: int = 0
        j: int = 0
        
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                return nums1[i]
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        
        return -1
      
    
def main() -> None:
    sol = Solution()
    print(sol.getCommon([1,2,5,7,9], [3,4,6,8,9]))

if __name__ == '__main__':
    main()
                
            
            
