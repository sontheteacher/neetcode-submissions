class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def compAnagrams(str1, str2) -> bool:
            if len(str1) != len(str2):
                return False
            count = [0] * 26
            for i in range(len(str1)):
                count[ord(str1[i]) - ord("a")] += 1
                count[ord(str2[i]) - ord("a")] -= 1
            for v in count:
                if v != 0:
                    return False
            return True
        
        result = []
        while len(strs) != 0:
            curr = strs.pop()
            flag = False
            for group in result:
                if compAnagrams(group[0], curr):
                    group.append(curr)
                    flag = True
            if not flag:
                result.append([curr])
                flag = False
        return result
