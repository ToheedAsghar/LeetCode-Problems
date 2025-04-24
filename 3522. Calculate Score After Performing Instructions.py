from typing import List

class Solution:
    def calculateScore(self, instructions: List[str], values: List[int]) -> int:
        visited: set = set() # to store visited indices
        n: int = len(instructions)
        cnt: int = 0

        i: int = 0
        while i<n and i not in visited:
            visited.add(i)
            if "jump" == instructions[i]:
                i = i + values[i]
            else: # add case
                cnt += values[i]
                i += 1

        return cnt

def main() -> None:
    sol = Solution()
    # instructions = ["jump","add","add","jump","add","jump"]
    # values = [2,1,3,1,-2,-3]

    # instructions = ["jump","add","add"]
    # values = [3,1,1]

    instructions = ["jump"]
    values = [0]

    print(sol.calculateScore(instructions, values))


if __name__ == '__main__':
    main()
