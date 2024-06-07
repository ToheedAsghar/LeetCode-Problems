class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        sen: List[str] = list(map(str, sentence.split()))
        retString = []
        
        for word in sen:
            currWord = word

            for root in dictionary:
                if word[:len(root)] == root and len(root) < len(currWord):
                    currWord = root
            
            retString.append(currWord)
    
        return ' '.join(retString)
