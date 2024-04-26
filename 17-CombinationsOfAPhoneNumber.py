from typing import List

class Solution:
    letters = {'1': '', '2':'abc', 
                   '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', 
                   '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
    def dfs(self, retList: List[str], digits: str, i: int, temp: str) -> None:        
        if i == len(digits):
            retList.append(temp)
            return

        n = len(self.letters[digits[i]])
        for j in range(n):
            key = digits[i]
            self.dfs(retList, digits, i+1, temp + self.letters[digits[i]][j])

    def letterCombination(self, digits: str) -> List[str]:
        retList = []
        self.dfs(retList, digits, 0, "")
        return retList


def main() -> None:
    sol = Solution()
    digits = ''
    print(sol.letterCombination(digits))

if __name__ == '__main__':
    main()
