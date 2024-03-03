'''
TC:     O(n*m)
SC:     O(n*m)
Link:   https://leetcode.com/problems/unique-paths/description/
'''
class Solution:
    def uniquePaths(self, n: int, m: int) -> int:
        paths: list[list[int]] = [[0 for j in range(m)] for i in range(n)]
    
        # making the first row and first column -> 1
        for i in range(n):
            paths[i][0] = 1
        for j in range(m):
            paths[0][j] = 1
        
        for i in range(n):
            for j in range(m):
                if paths[i][j] == 1:
                    pass
                else:
                    paths[i][j] = paths[i-1][j] + paths[i][j-1]

        return paths[n-1][m-1]
            

def main() -> None:
    n: int = 5
    m: int = 5
    sol = Solution()
    print(sol.uniquePaths(n,m))
    
if __name__ == '__main__':
    main()