import numpy as np
from numpy.linalg import matrix_power as mp
A = np.array([[4,2,4],[4,-1,1],[2,4,2]])
B = np.array([[5,2,3],[3,-7,5],[3,1,-1]])

print(A+B,'\n')
print(A*B)
print(20+12-6)

print('\n',mp((A@B),-1),'\n')
print(mp(B,-1)@mp(A,-1))