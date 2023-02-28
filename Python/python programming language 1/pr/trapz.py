from sympy import *
# def trapzrule(f, p, q, n=50):
#     x = np.linspace(p, q, n+1)
#     y = f(x)
#     y_right = y[1:]  # right endpoint
#     y_left = y[:-1]  # left  endpoint
#     dx = (q - p)/n
#     t = (dx/2) * np.sum(y_right + y_left)
#     return t
# r = trapzrule(np.sin, 0, np.pi/2, 1000)
# print(r)

import numpy as np
def trapzrule(f, x0, x, u):
    y = f(np.linspace(x0, x, u+1))  # range dividing
    h = (x - x0)/u
    return h*((1/2*(y[0]+y[len(y)-1]))+np.sum(y[1:-1]))


ans = trapzrule(lambda x: x*2, 0, 6, 5)
print(ans)

print(np.ones((5, 5)))

print(zeros(5, 4))
