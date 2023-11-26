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
plt.grid()
plt.show()



# import matplotlib.pyplot as plt
# import numpy as np
# rand_arr = np.random.randint(0,100,50)

# print("\n Random Numbers:",rand_arr)
# x = rand_arr
# y = x*0.5
# print("Line Chart")
# plt.plot(x,'-',color="r", linewidth=3)
# plt.xlabel("X-axis")
# plt.title("Line Chart")
# plt.minorticks_on()
# plt.show()
