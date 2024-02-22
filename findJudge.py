from typing import List
from icecream import ic
class Solution:
    # TC:O(k) SC:O(k) where k = len(trust) 
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        incoming = [0] * (n + 1)
        outgoing = [0] * (n + 1)
        
        for it in trust:
            outgoing[it[0]] += 1
            incoming[it[1]] += 1
        
        for i in range(1, n+1):
            if outgoing[i] == 0 and incoming[i] == n-1:
                return i
        return -1
    
    def findJudgeII(self, n: int, trust: List[List[int]]) -> int:
       
        # edge case
        if 1 == n and 0 == len(trust):
            return n
       
        people = []
        size = len(trust)
        judges = {}
        cnt = 0
        for i in range(size):
            if trust[i][0] in judges.keys():
                del judges[trust[i][0]]
            if trust[i][0] not in people:
                people.append(trust[i][0])
            
            if trust[i][1] not in people:
                judges[trust[i][1]] = judges.get(trust[i][1], 0) + 1
        
        judge = -1
        trustLevel = -1
        for key,value in judges.items():
            judge, trustLevel = key,value
            
        return -1 if n-1 != value else judge

'''
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
Input: n = 4, trust = [[1,2],[1,3],[2,1],[2,3],[1,4],[4,3],[4,1]]
Output: 3
'''
sol = Solution()
print(sol.findJudge(4, [[1,2],[1,3],[2,1],[2,3],[1,4],[4,3],[4,1]]))


                
            
                