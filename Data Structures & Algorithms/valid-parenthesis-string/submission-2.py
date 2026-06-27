class Solution:
    def checkValidString(self, s: str) -> bool:
        left_st = []
        star_st = []
        for i in range(len(s)):
            if s[i] == '*':
                star_st.append(i)
            elif s[i] == '(':
                left_st.append(i)
            else: 
                # we encounter ')'
                if left_st:
                    left_st.pop()
                elif star_st:
                    star_st.pop()
                else:
                    return False
        
        while left_st and star_st:
            if left_st[-1] < star_st[-1]:
                left_st.pop()
                star_st.pop()
            else:
                return False
        
        return not bool(left_st)