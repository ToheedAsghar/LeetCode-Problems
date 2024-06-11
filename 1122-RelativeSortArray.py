from collections import Counter
from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        hm = Counter(arr1)
        i: int = 0
        tempArray = []
        
        while i < len(arr2):
            val: int = hm[arr2[i]]
            j: int = 0
            while j < val:
                tempArray.append(arr2[i])
                j += 1
            i += 1

        tmp = []
        tmpSet = set(arr2)
        for ele in arr1:
            if ele not in tmpSet:
                tmp.append(ele)
        
        return tempArray + sorted(tmp)

if __name__ == '__main__':
    sol = Solution()
    arr1 = [2,3,1,3,2,4,6,7,9,2,19]
    arr2 = [2,1,4,3,9,6]

    print(sol.relativeSortArray(arr1, arr2))
