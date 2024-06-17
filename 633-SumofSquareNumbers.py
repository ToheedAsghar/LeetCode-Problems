class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a: int = 0
        b: int = 0

        while a <= b:
            mid = a**2 + b**2

            if mid == c:
                return True
            elif mid > c:
                b -= 1
                a += 1
            else:
                b += 1
        
        return False
