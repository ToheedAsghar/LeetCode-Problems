# https://leetcode.com/problems/group-anagrams/description/

'''
TC: O(NKlogK)
N -> size of list[strs]
K -> size of maximum str in str
KlogK -> sorting in nested loop
'''
def groupAnagrams(strs):
    anagrams = {}
    for str in strs:
        word = ''.join(sorted(str))
        if word not in anagrams:
            anagrams[word] = [str]
        else:
            anagrams[word].append(str)
    return list(anagrams.values())
    
print(groupAnagrams( ["abc", "cba", 'a']))
    


