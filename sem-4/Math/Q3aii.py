# Import PuLP library
import pulp

# Create a maximization problem object
problem = pulp.LpProblem('LP Problem', pulp.LpMaximize)

# Define decision variables
x1 = pulp.LpVariable('x1', lowBound=0)
x2 = pulp.LpVariable('x2', lowBound=0)
x3 = pulp.LpVariable('x3', lowBound=0)

# Define objective function
problem += 3*x1 + 5*x2 + 4*x3, 'Z'

# Define constraints
problem += 2*x1 + 3*x2 <= 8
problem += 2*x2 + 5*x3 <= 10
problem += 3*x1 + 2*x2 + 4*x3 <= 15

# Solve the problem
status = problem.solve()

# Print the solution status
print('Status:', pulp.LpStatus[status])

# Print the optimal solution
print('Optimal Solution:')
print('x1 =', pulp.value(x1))
print('x2 =', pulp.value(x2))
print('x3 =', pulp.value(x3))
print('Z =', pulp.value(problem.objective))
