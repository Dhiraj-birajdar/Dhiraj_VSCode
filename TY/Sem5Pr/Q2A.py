#Generate a random array of 50 integers and display them using a line chart, scatter plot.
#Apply appropriate color, labels and styling options.

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Set a seed for reproducibility
np.random.seed(42)

# Generate a random array of 50 integers between 1 and 100
random_array = np.random.randint(1, 100, 50)

# Line chart
plt.figure(figsize=(10, 4))
plt.plot(random_array, marker='o', color='blue', linestyle='-', linewidth=2)
plt.title('Line Chart')
plt.xlabel('Index')
plt.ylabel('Value')
plt.grid(True)
plt.show()

# Scatter plot
plt.figure(figsize=(10, 4))
plt.scatter(range(50), random_array, color='green', marker='o')
plt.title('Scatter Plot')
plt.xlabel('Index')
plt.ylabel('Value')
plt.grid(True)
plt.show()

# Histogram
plt.figure(figsize=(10, 4))
sns.histplot(random_array, bins=15, kde=True, color='purple')
plt.title('Histogram')
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.grid(True)
plt.show()

# Box plot
plt.figure(figsize=(8, 6))
sns.boxplot(y=random_array, color='orange')
plt.title('Box Plot')
plt.ylabel('Value')
plt.grid(True)
plt.show()
