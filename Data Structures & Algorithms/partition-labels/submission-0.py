class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # have a dictionary keep track of start and end
        # index of each character
        # then merge overlapping intervals

        index = {}
        for c in range(len(s)):
            if s[c] not in index:
                index[s[c]] = (c, c)
            else:
                index[s[c]] = (index[s[c]][0], c)
            print(s[c], index[s[c]])
        
        res = []
        curr = [-1, -1]
        for i in range(len(s)):
            if curr[0] == -1:
                curr = list(index[s[i]])
            if i >= curr[1]:
                res.append(curr[1] - curr[0] + 1)
                curr = [-1, -1]
            else:
                curr[1] = max(curr[1], index[s[i]][1])
        return res
