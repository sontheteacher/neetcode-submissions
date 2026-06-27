class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        stack = []
        for i in range(len(temperatures)):
            if not stack:
                stack.append(i)
            elif temperatures[i] <= temperatures[i - 1]:
                stack.append(i)
            else:
                res[stack.pop()] = 1 # Pop the most recent element
                if stack:
                    x = stack[-1]
                    while temperatures[x] < temperatures[i]:
                        res[x] = i - x
                        stack.pop()
                        if stack:
                            x = stack[-1]
                        else:
                            break
                stack.append(i)
        return res