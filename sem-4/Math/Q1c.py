import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
# Generate x and y values
x = np.linspace(-10, 10, 100)
y = np.linspace(-10, 10, 100)
# Create a meshgrid of x and y values
X, Y = np.meshgrid(x, y)
# Compute z values for the function z = sin(x) + cos(y)
Z = np.sin(X) + np.cos(Y)
# Create a 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z)
# ax.set_xlabel('x')
# ax.set_ylabel('y')
# ax.set_zlabel('z')
# ax.set_title('3D Plot of z = sin(x) + cos(y)')
plt.show()
