class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        md = {'(': ')', '{': '}', '[':']'}
        l = ['(', '{', '[']
        r = [')', '}', ']']
        for i in range(len(s)):
            if s[i] in l:
                stack.append(s[i])
            else:
                if len(stack) == 0:
                    return False
                el = stack.pop()
                if md[el] != s[i]:
                    return False
        return True if not stack else False
        