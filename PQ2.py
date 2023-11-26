import matplotlib.pyplot as plt
import numpy as np
from random import choices 

x = range(1,51)
y = np.random.randint(1,100,50)

plt.plot(x,y, marker='d',markerfacecolor='red', markersize=6, color='green', linewidth=2, label='Integer')

plt.xlabel("Points")
plt.ylabel("Random Integers")
plt.title("Line chart")
plt.legend(loc='lower right')
plt.grid()
plt.show()

rng = np.random.RandomState(0)
colors = rng.rand(50)
sizes = 1000*rng.rand(50)

plt.scatter(x,y, c=colors, s=sizes, alpha=0.3, marker='o')
plt.xlabel('Points')
plt.ylabel('Random Integers')
plt.title("Scatter Plot")
plt.grid()
plt.show()











import matplotlib.pyplot as plt

sub = ["English", "Data Science", "C", "DBMS", "Math"]
marks = [88, 78, 98, 95, 65]
colors = ['red', "blue", 'pink', 'orange', 'yellow']
explode = (0,0,0,0,0.1)

plt.pie(marks, explode=explode, labels=sub, colors=colors, autopct="%1.1f%%", shadow=False)
plt.axis('equal')
plt.title("Pie chart")
plt.show()












import pandas as pd
data = pd.read_csv("winequality-red.csv")

print("a) Describing the dataset:")
print(data.describe())
print("\n")

print(f"b) Shape of the dataset: {data.shape}")
print("\n")

print("c) Display first 3 rows from the dataset:")
print(data.head(3))