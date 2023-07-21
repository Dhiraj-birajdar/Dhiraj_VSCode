# (i) Write a Python program to solve the following LPP:
# Min Z = 3.5x + 2y
# subject to x + y ≥ 5
# x ≥ 4
# y ≤ 2
# x ≥ 0, y ≥ 0.

# Import PuLP library
import pulp

# Create a maximization problem object
problem = pulp.LpProblem('LP Problem', pulp.LpMinimize)

# Define decision variables
x = pulp.LpVariable('x', lowBound=0)
y = pulp.LpVariable('y', lowBound=0)

# Define objective function
problem += 3.5*x + 2*y, 'Z'

# Define constraints
problem += x + y >= 5
problem += x >= 4
problem += y <= 2

# Solve the problem
status = problem.solve()

# Print the solution status
print('Status:', pulp.LpStatus[status])

# Print the optimal solution
print('Optimal Solution:')
print('x =', pulp.value(x))
print('y =', pulp.value(y))
print('Z =', pulp.value(problem.objective))
















# Define the objective function coefficients
c = [3.5, 2]

# Define the left-hand side coefficients of the constraints
A = [[1, 1],
     [-1, 0],
     [0, -1]]

# Define the right-hand side values of the constraints
b = [5, -4, 2]

# Define the bounds for the decision variables
x_bounds = (4, None)
y_bounds = (None, 2)

# Import the linprog function from the scipy.optimize module
from scipy.optimize import linprog

# Apply the simplex method
result = linprog(c, A_ub=A, b_ub=b, bounds=[x_bounds, y_bounds], method='simplex')

# Print the solution status
print('Status:', 'Optimal' if result.success else 'Infeasible')

# Print the optimal solution
if result.success:
    print('Optimal Solution:')
    print('x =', result.x[0])
    print('y =', result.x[1])
    print('Z =', result.fun)
