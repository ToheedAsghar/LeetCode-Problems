# https://leetcode.com/problems/perfect-squares/description/
'''
TC: 
    O(sqrt(n)) for inner loop & O(n) for outer loop
    Time Complexity: O(n*sqrt(n))
SC:
    O(n)
'''

class Solution:
    def numSquares(self, n: int) -> int:
        memo = [float('inf')] * (n+1)
        memo[0] = 0

        # generating sqaures
        sqs = []
        i = 1
        while i*i <= n:
            sqs.append(i*i)
            i += 1


        for i in range(1, n+1):
            for j in sqs:
                memo[i] = min(memo[i], memo[i-j] + 1)
        
        return memo[n]

sol = Solution();
print(sol.numSquares(12))
