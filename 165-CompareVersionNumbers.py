class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        i, j, k, l = 0, 0, 0, 0
        n = len(version1)
        m = len(version2)

        while i < n or k < m:
            while j < n and '.' != version1[j]:
                j += 1
            while l < m and '.' != version2[l]:
                l += 1

            num1: int = 0
            num2: int = 0

            if i >= n:
                num1 = 0
            else:
                num1 = int(version1[i:j])
                j += 1
                i = j 
            if k >= m:
                num2 = 0
            else:
                num2 = int(version2[k:l])
                l += 1
                k = l

            if num1 < num2:
                return -1
            elif num1 > num2:
                return 1
        return 0



def main() -> None:
    sol = Solution()

    version1 = '0.1.01.0.0.1'
    version2 = '0.1.01'
    
    print(sol.compareVersion(version1, version2))

if __name__ == '__main__':
    main()
