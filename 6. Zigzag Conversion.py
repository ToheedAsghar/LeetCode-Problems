# from typing import List

class Solution:
    def convert(self, s: str, numRows: int) -> str:

        if 1 == numRows:
            return s

        n: int = len(s)
        result: str = ""
        if 2 == numRows:
            for i in range(0, n, 2):
                result += s[i]
            for i in range(1, n, 2):
                result += s[i]
            
            return result

        m: int = n // numRows
        grid: List[List[str]] = [[None]*(n) for _ in range(numRows)]

        dFlag: bool = False # means row
        r: int = 0
        c: int = 0
        i: int = 0
        while i < n:
            if dFlag:
                grid[r][c] = s[i]
                r -= 1
                c += 1

                if r <=0:
                    r = 0
                    dFlag = False
            elif r < numRows:
                grid[r][c] = s[i]
                r += 1
            else:
                r = numRows - 2
                c += 1
                dFlag = True
                continue
        
            i += 1

        # for row in grid:
        #     for ch in row:
        #         if ch is not None:
        #             print(ch, end=" ")
        #         else:
        #             print("_", end=" ")
        #     print()


        result: str = ""
        for row in grid:
            for ch in row:
                if ch is not None:
                    result += ch

        return result
        

# def main() -> None:
#     sol = Solution()
#     s: str = "PAYPALISHIRING" # result = PAHNAPLSIIGYIR
#     print(sol.convert(s, 3))

#     # s: str = "PAYPALISHIRING" # result = PINALSIGYAHRPI
#     # print(sol.convert(s, 4))

#     # s: str = "A" # result = A
#     # print(sol.convert(s, 1))


# if __name__ == '__main__':
#     main()
