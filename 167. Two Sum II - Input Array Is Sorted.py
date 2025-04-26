class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        a, b = 0, 0

        n: int = len(numbers)

        assert(n>=2, "bounds error")

        i: int = 0
        j: int = n - 1

        while i < j:
            m: int = numbers[i] + numbers[j] 
            if m == target:
                return [i+1, j+1]
            elif m > target:
                j -= 1
            else:
                i += 1
        
        return []
