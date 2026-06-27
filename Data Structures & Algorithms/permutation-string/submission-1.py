class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        if len(s2) < len(s1):
            return False

        def check_window(window, s1_d):
            # Check if window is equal to s1
            for key in s1_d.keys():
                if s1_d[key] != window.get(key, -1):
                    return False
            return True
        
        s1_c = {} # Count of characters in s1
        for c in s1:
            s1_c[c] = 1 + s1_c.get(c, 0)
        l, r = 0, len(s1) - 1
        window = {}
        
        # Create the initial window
        for c in range(len(s1)):
            window[s2[c]] = 1 + window.get(s2[c], 0)
        
        # Slide the fixed window
        while r < len(s2) - 1:
            if check_window(window, s1_c):
                return True
            print(window)
            window[s2[l]] -= 1
            l += 1
            r += 1
            window[s2[r]] = 1 + window.get(s2[r], 0)
        return check_window(window, s1_c)