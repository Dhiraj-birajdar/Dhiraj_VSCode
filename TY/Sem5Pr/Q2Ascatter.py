#Generate a random array of 50 integers and display them using a line chart, scatter plot.
#Apply appropriate color, labels and styling options.

import matplotlib.pyplot as plt
from random import choices 
import numpy as np

x = range(1,51)
y = choices(range(1,101),k=50)

rng = np.random.RandomState(0)
colors = rng.rand(50)
sizes = 1000*rng.rand(50)
# print(sizes)

plt.scatter(x,y, c=colors, s=sizes, alpha=0.3, marker='o')
plt.xlabel('Points')
plt.ylabel('Random Integers')
plt.title("Scatter Plot")
plt.show()

