class Solution:
    def removeElement(self, nums, val):
        i = 0
        j = len(nums)

        if 0 == len(nums) or (1 == len(nums) and nums[0] != val):
            return len(nums)

        while i < j:
            if nums[i] == val:
                j -= 1
                while j > i and nums[j] == val:
                    j -= 1

                if i == j:
                    return i

                nums[i], nums[j] = nums[j], nums[i]

            i += 1

        return i



if __name__ == '__main__':
    sol = Solution()
    nums = [3, 3]
    val = 5
    print(sol.removeElement(nums, val))

