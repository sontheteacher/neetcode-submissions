import operator

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        ops =   {
            '+' : operator.add,
            '-' : operator.sub,
            '*' : operator.mul,
            '/' : operator.truediv
        }
        for i in range(len(tokens)):
            c = tokens[i]
            if c.isnumeric() or (c[0] == '-' and len(c) > 1):
                stack.append(int(c))
            else:
                y = stack.pop()
                x = stack.pop()
                stack.append(int(ops[c](x, y)))
        return stack[0]