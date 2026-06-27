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
                j = 0
                while j < len(stack):
                    if temperatures[i] > temperatures[stack[j]]:
                        res[stack[j]] = i - stack[j]
                        stack.pop(j)
                    else:
                        j += 1
                stack.append(i)
                print(stack)
        return res