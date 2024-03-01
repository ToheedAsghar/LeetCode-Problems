class Solution:
    # TC: O(n)          SC(1)
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt1: int = s.count('1')
        cnt0: int = s.count('0')
        
        return '1'*(cnt1-1) + '0'*(cnt0) + '1'
      
    # TC: O(NLogN)      SC:     O(1)  
    def maximumOddBinaryNumberI(self, s: str) -> str:
        n = len(s)
        s = sorted(s, reverse=True)
        if '0' == s[n-1]:
            for i in range(n-2, -1, -1):
                if '1' == s[i]:
                    s[i], s[n-1] = s[n-1], s[i]
                    break
        return ''.join(s)

    # TC: O(n**2)       SC: O(n)
    def maximumOddBinaryNumberII(self, s: str) -> str:
        n = len(s)
        tempList = list(s)
        if s[n-1] != '1':
            for i in range(n-2, -1, -1):
                if '1' == tempList[i]:
                    tempList[i],tempList[n-1] = tempList[n-1], tempList[i]
                    break

        for i in range(0,n-1):
            if tempList[i] != '1':
                for j in range(i+1, n-1):
                    if('1' == tempList[j]):
                        tempList[i], tempList[j] = tempList[j], tempList[i]
                
        return ''.join(tempList)

# 0111 -> 1101
# 10010 -> 10001

sol = Solution()
print(sol.maximumOddBinaryNumber("10010"))