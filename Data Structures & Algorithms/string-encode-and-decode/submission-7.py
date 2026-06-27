class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for word in strs:
            res += str(len(word)) + "#" + word
        return res

    def decode(self, s: str) -> List[str]:
        if s == "#":
            return []
        res = []
        index = s.find("#")
        i = 0
        while i < len(s):
            index = i + 1
            while s[index] != '#':
                index += 1
            length = int(s[i:index])
            i = index + length + 1
            res.append(s[index + 1: i])
        return res


        