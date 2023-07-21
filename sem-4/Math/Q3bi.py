# (i) Apply Python program in each of the following transformations on the point P[4, −2]
# (I) Refection through Y−axis.
# (II) Scaling in X−coordinate by factor 3.
# (III) Scaling in Y−coordinate by factor 2.5
# (IV) Reflection through the line y = −x

import numpy as np
p = np.matrix([4, -2])

rf = np.matrix([[-1, 0], [0, 1]])
print('Refection through Y-axis : ',np.dot(p, rf))

scx = np.matrix([[3, 0], [0, 1]])
print('Scaling in X-coordinate by factor 3 : ', np.dot(p, scx))

scy = np.matrix([[1, 0], [0, 2.5]])
print('Scaling in Y-coordinate by factor 2.5 : ', np.dot(p, scy))

rfy = np.matrix([[0, -1], [-1, 0]])
print('Reflection through the line y = -x : ',np.dot(p, rfy))
