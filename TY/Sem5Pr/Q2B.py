#Q.2 B) Create two lists, one representing subject names and the other representing marks obtained in those subjects. 
#Display the data in a pie chart.

import matplotlib.pyplot as plt

sub = ["English", "Data Science", "C", "DBMS", "Math"]
marks = [88, 78, 98, 95, 65]
colors = ['red', "blue", 'pink', 'orange', 'yellow']
explode = (0,0,0,0,0.1)

plt.pie(marks, explode=explode, labels=sub, colors=colors, autopct="%1.1f%%", shadow=False)
plt.axis('equal')
plt.title("Pie chart")
plt.show()


