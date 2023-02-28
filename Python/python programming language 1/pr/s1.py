import numpy as np
from sympy import*
# #Q1. (2)
s1="Python "
s2="Mathematics "

print(s1*9)
print(s2*9)

# # (3)
for i in range(1,11):
    print('square of ',i,' is ',i*i)

# #Q2. (1)
# # 1
print(np.eye(10))
# # 2
print(zeros(7,3))
# # 3 
print(ones(5,4))

# (3)
for x in range(1,101):
    p=1
    for i in range(2,x):
        if x%i!=0:
            p=0
    if p==1:
        print(x)

import math
def pr():
    for x in range(1,101):
        p=1
        for i in range(1,x):
            if math.gcd(i,x)!=1:
                p=0
        if p==1:
            print(x)
pr()

