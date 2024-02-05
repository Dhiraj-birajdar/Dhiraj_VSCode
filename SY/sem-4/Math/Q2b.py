import numpy as np

# Define original line points
A = np.array([2, 1])
B = np.array([4, -1])
# Define transformation matrix [T]
T = np.array([[1, 2], [2, 1]])
# Find transformed points A' and B'
A_transformed = np.dot(T, A)
B_transformed = np.dot(T, B)
# Extract coordinates of transformed points
x1_transformed, y1_transformed = A_transformed
x2_transformed, y2_transformed = B_transformed
# Find equation of transformed line
m_transformed = (y2_transformed - y1_transformed) / (x2_transformed - x1_transformed)
b_transformed = y1_transformed - m_transformed * x1_transformed
# Format the equation of the transformed line
equation_transformed = f"y = {m_transformed} * x + {b_transformed}"
print("Equation of transformed line: ", equation_transformed)
