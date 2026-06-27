class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return "\0"
        elif len(strs) == 1:
            return strs[0]
        return "\0".join(strs)
    def decode(self, s: str) -> List[str]:
        if s == "\0":
            return []
        if s == "":
            return [""]
        return s.split("\0")