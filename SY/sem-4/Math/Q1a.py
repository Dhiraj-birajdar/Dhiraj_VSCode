import numpy as np
import matplotlib.pyplot as plt
# Generate x values
x = np.linspace(0, 2*np.pi)
# Compute y values for cos(x)
y = np.cos(x)
# Plot f(x) = cos(x)
plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('f(x) = cos(x)')
plt.title('Graph of f(x) = cos(x)')
# plt.grid(True)
plt.show()
