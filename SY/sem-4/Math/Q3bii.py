# (ii) Find the combined transformation of the line segment between the points A[2, −1] & B[5, 4]
# by using Python program for the following sequence of transformations:-
# (I) Rotation about origin through an angle π.
# (II) Scaling in X−coordinate by 3 units.
# (III) Shearing in X direction by 6 units.
# (IV) Reflection through the line y = x.

import numpy as np

a = np.matrix([2, -1])
b = np.matrix([5, 4])

ro = np.matrix([[int(np.cos(np.pi)), int(np.sin(np.pi))], [int(-np.sin(np.pi)), int(np.cos(np.pi))]])

scx = np.matrix([[3, 0], [0, 1]])

shx = np.matrix([[1, 0], [6, 1]])

rfy = np.matrix([[0, 1], [1, 0]])

t = ro * scx * shx * rfy

print(np.dot(a, t))
print(np.dot(b, t))



