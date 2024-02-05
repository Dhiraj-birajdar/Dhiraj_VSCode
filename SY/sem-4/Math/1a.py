import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0, 2*np.pi, 0.1)
y = np.cos(x)

plt.plot(x, y)

# plt.xlabel("x")
# plt.ylabel("cos(x)")

plt.show()