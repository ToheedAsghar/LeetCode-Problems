class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        cnt = 0
        maxHapp = 0
        n = len(happiness)

        for i in range(n):
            if k and happiness[i] :
                curr = happiness[i] - cnt
                if curr < 0:
                    continue
                maxHapp += cur
                cnt += 1
                k -= 1
            else:
                break
            
        return maxHapp
