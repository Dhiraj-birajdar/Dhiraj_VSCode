import matplotlib.pyplot as plt

l = [1,2,3,4,5]
h = [65, 30, 54, 10, 20]
n = ['cricket', 'football', 'hockey', 'chess', 'tennis']

plt.bar(l,h,tick_label = n, width = 0.7, color = ['red', 'green'])
plt.show()
