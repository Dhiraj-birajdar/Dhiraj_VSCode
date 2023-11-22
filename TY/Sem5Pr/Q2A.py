#Generate a random array of 50 integers and display them using a line chart, scatter plot.
#Apply appropriate color, labels and styling options.

import matplotlib.pyplot as plt
from random import choices 
x = range(1,51)
y = choices(range(1,101),k=50)

plt.plot(x,y, marker='d',markerfacecolor='red', markersize=6, color='green', linewidth=2, label='Integer')

plt.xlabel("Points")
plt.ylabel("Random Integers")
plt.title("Line chart")
# plt.hist(y,edgecolor="black")
# plt.bar(y, height=50)
plt.legend(loc='lower right')
plt.show()

