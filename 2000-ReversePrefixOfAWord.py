# https://leetcode.com/problems/reverse-prefix-of-word/description/?

class Solution():
    def reversePrefix(self, word: str, ch: str) -> str:
        index = word.find(ch)
        return word[:index+1][::-1] + word[index+1:]
        
if __name__ == '__main__':
    sol = Solution()
    #word = 'abcdefd'
    #ch = 'd'
    word = "xyxzxe"
    ch = "z"
    print(sol.reversePrefix(word, ch))
