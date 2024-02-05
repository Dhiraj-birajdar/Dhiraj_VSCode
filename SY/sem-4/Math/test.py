#Q1a
import matplotlib.pyplot as plt
import numpy as np
x = np.arange(0, 2*np.pi, 0.1)
y = np.cos(x)
plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('f(x) = cos(x)')
plt.title('Graph of f(x) = cos(x)')
plt.show()


#Q1b
import matplotlib.pyplot as plt
l = [1,2,3,4,5]
h = [65, 30, 54, 10, 20]
tick_label = ['cricket', 'football', 'hockey', 'chess', 'tennis']
plt.bar(l,h,tick_label = tick_label, width = 0.7, color = ['red', 'green'])
plt.xlabel('Games')
plt.ylabel('No.Of Student')
plt.show()


#Q1c
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
x = np.linspace(-10, 10, 100)
y = np.linspace(-10, 10, 100)
X, Y = np.meshgrid(x, y)
Z = np.sin(X) + np.cos(Y)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('3D Plot of z = sin(x) + cos(y)')
plt.show()


#Q2a
import numpy as np
A = np.array([5, 3])
B = np.array([1, 4])
def reflect(line, point):
    m = line[0]
    c = line[1]
    x, y = point
    x_reflect = (2 * m * (y - c) + x * (m ** 2 - 1)) / (m ** 2 + 1)
    y_reflect = (2 * m * x + y * (1 - m ** 2) + 2 * c) / (m ** 2 + 1)
    return np.array([x_reflect, y_reflect])
line = np.array([1, -1])
A_reflected = reflect(line, A)
B_reflected = reflect(line, B)
print("Reflected Point A':", A_reflected)
print("Reflected Point B':", B_reflected)


#Q2b
import numpy as np
A = np.array([2, 1])
B = np.array([4, -1])
T = np.array([[1, 2], [2, 1]])
A_transformed = np.dot(T, A)
B_transformed = np.dot(T, B)
x1_transformed, y1_transformed = A_transformed
x2_transformed, y2_transformed = B_transformed
m_transformed = (y2_transformed - y1_transformed) / (x2_transformed - x1_transformed)
b_transformed = y1_transformed - m_transformed * x1_transformed
equation_transformed = f"y = {m_transformed} * x + {b_transformed}"
print("Equation of transformed line: ", equation_transformed)


#Q2c
x1, y1 = 0, 0
x2, y2 = 10, 10
midpoint_x = (x1 + x2) / 2
midpoint_y = (y1 + y2) / 2
print("Midpoint: ({}, {})".format(midpoint_x, midpoint_y))

#Q3a i
c = [3.5, 2]
A = [[1, 1],
     [-1, 0],
     [0, -1]]
b = [5, -4, 2]
x_bounds = (4, None)
y_bounds = (None, 2)
from scipy.optimize import linprog
result = linprog(c, A_ub=A, b_ub=b, bounds=[x_bounds, y_bounds], method='simplex')
print('Status:', 'Optimal' if result.success else 'Infeasible')
if result.success:
    print('Optimal Solution:')
    print('x =', result.x[0])
    print('y =', result.x[1])
    print('Z =', result.fun)
    
    
#Q3a ii
import pulp
problem = pulp.LpProblem('LP Problem', pulp.LpMaximize)
x1 = pulp.LpVariable('x1', lowBound=0)
x2 = pulp.LpVariable('x2', lowBound=0)
x3 = pulp.LpVariable('x3', lowBound=0)
problem += 3*x1 + 5*x2 + 4*x3, 'Z'
problem += 2*x1 + 3*x2 <= 8
problem += 2*x2 + 5*x3 <= 10
problem += 3*x1 + 2*x2 + 4*x3 <= 15
status = problem.solve()
print('Status:', pulp.LpStatus[status])
print('Optimal Solution:')
print('x1 =', pulp.value(x1))
print('x2 =', pulp.value(x2))
print('x3 =', pulp.value(x3))
print('Z =', pulp.value(problem.objective))


#Q3b i
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


#Q3b ii
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
