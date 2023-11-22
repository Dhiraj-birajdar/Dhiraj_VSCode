#Q.2 B) Create two lists, one representing subject names and the other representing marks obtained in those subjects. 
#Display the data in a pie chart.

import matplotlib.pyplot as plt

sub = ["English", "Data Science", "C", "DBMS", "Math"]
marks = [88, 78, 98, 95, 70]
colors = ['red', "blue", 'pink', 'orange', 'yellow']
explode = (0,0,0,0,0.1)

plt.pie(marks, explode=explode, labels=sub, colors=colors, autopct="%1.1f%%", shadow=False)
# circle = plt.Circle((0,0), 0.75, color='black', fc='white', linewidth=1.25)
# figure = plt.gcf()
# figure.gca.add_artist(circle)
plt.axis('equal')
plt.title("Pie chart")
plt.show()


