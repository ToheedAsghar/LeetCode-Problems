from icecream import ic
class Solution:
    def numSteps(self, s: str) -> int:
        s = list(s)
        j: int = len(s) - 1
        steps: int = 0

        while j > 0:
            if '1' == s[j]:
                t: int = j
                while '1' == s[t]: 
                    s[t] = '0'
                    t -= 1
                    if 0 == t:
                        j += 1
                        if j >= len(s):
                            s.append('0')
                        break
                s[t] = '1'
            else:
                j -= 1
            steps += 1
        return steps


if __name__ == '__main__':
    sol = Solution()
    s = '1'
    # s = '10101'

    print(sol.numSteps(s))

