#Generate a random array of 50 integers and display them using a line chart, scatter plot.
#Apply appropriate color, labels and styling options.

import matplotlib.pyplot as plt
from random import choices 
arr = choices(range(1,101),k=50)

plt.plot(arr[:25],arr[25:])
# plt.plot([1,2,3],[3,2,1])
# plt.hist(arr,edgecolor="black")
# plt.bar(arr, height=50)
plt.show()

