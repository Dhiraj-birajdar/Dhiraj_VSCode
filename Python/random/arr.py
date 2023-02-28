
import numpy as np
a = np.array([1,2,3,4])
print(a)
print(a.shape)
print(a.ndim)

a2 = np.array([[1],[5],[2],[6]])
print(a2)
print(a2.shape)
print(a2.ndim)
mul = a @ a2
print(mul)
print(mul.shape)
print(mul.ndim)
