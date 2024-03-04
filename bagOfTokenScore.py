'''
TC:         O(n)
SC:         O(1)
Link:       https://leetcode.com/problems/bag-of-tokens/
'''

from typing import List
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        # edge cases
        if 0 == len(tokens):
            return 0

        tokens.sort()
        if power < tokens[0]:
            return 0
        
        i: int = 0
        n = len(tokens)
        j: int = n-1
        score: int = 0

        while i <= j:
            if i != j and power < tokens[i]:
                # if i == j then face-down not possible
                score -= 1
                power += tokens[j]
                j -= 1
            elif power >= tokens[i]:
                score += 1
                power -= tokens[i]
                i += 1
            else:
                break
        
        return score


def main() -> None:
    sol = Solution()
    print(sol.bagOfTokensScore([100, 300, 200, 400], 200))


if __name__ == '__main__':
    main()
        