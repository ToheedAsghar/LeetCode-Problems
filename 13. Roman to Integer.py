# from icecream import ic

class Solution:
    def __init__(self):
        self.roman = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
            "IV": 4,
            "IX": 9,
            "XL": 40,
            "XC": 90,
            "CD": 400,
            "CM": 900,
        }

        self.subtractRoman = set({"I", "X", "C"})

    def romanToInt(self, s: str) -> int:
        n: int = len(s)
        retVal: int = 0
        i: int = 0
        while i < n:
            if s[i] in self.subtractRoman and i+1 < n and s[i:i+2] in self.roman:
                retVal += self.roman[s[i: i+2]]
                i += 1
            else:
                retVal += self.roman[s[i]]
            
            i += 1
        
        return retVal

# def main() -> None:
#     sol = Solution()
#     s = input().strip()
#     retVal: int = sol.romanToInt(s)
#     print(retVal)

# if __name__ == '__main__':
#     main()
