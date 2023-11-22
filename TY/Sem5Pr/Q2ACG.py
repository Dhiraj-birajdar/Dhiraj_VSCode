import numpy as np
import matplotlib.pyplot as plt

# Generate a random array of 50 integers
np.random.seed(42)  # Setting a seed for reproducibility
random_array = np.random.randint(0, 100, 50)

# Line chart
plt.figure(figsize=(10, 5))
plt.plot(random_array, marker='o', color='blue', linestyle='-', linewidth=2, markersize=8, label='Line Chart')
plt.title('Line Chart of Random Integers')
plt.xlabel('Index')
plt.ylabel('Value')
plt.legend()
plt.grid(True)
plt.show()

# Scatter plot
plt.figure(figsize=(10, 5))
plt.scatter(range(len(random_array)), random_array, color='red', marker='x', label='Scatter Plot')
plt.title('Scatter Plot of Random Integers')
plt.xlabel('Index')
plt.ylabel('Value')
plt.legend()
plt.grid(True)
plt.show()
