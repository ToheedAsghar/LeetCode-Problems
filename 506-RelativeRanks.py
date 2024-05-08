class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        zipList = []
        n = len(score)

        for i in range(n):
            zipList.append([score[i], i])

        zipList.sort(reverse=True)

        for i in range(n):
            if 0 == i:
                score[zipList[i][1]] = 'Gold Medal'
            elif 1 == i:
                score[zipList[i][1]] = 'Silver Medal'
            elif 2 == i:
                score[zipList[i][1]] = 'Bronze Medal'
            else:
                score[zipList[i][1]] = str(i+1)
        
        return score
