#Q.2 C) Write a program in python to perform following task (Use winequality-red.csv )
#Import Dataset and do the followings:
#a) Describing the dataset
#b) Shape of the dataset
#c) Display first 3 rows from dataset

import pandas as pd

# Load the dataset
dataset = "H:\GITHUB\Dhiraj_VSCode\TY\Sem5Pr\winequality-red.csv"
try:
    data = pd.read_csv(dataset)
except(FileNotFoundError):
    print("File not found")
    exit(0)

# a) Describing the dataset
description = data.describe()
print("a) Describing the dataset:")
print(description)
print("\n")

# b) Shape of the dataset
shape = data.shape
print(f"b) Shape of the dataset: {shape}")
print("\n")

# c) Display first 3 rows from dataset
first_three_rows = data.head(3)
print("c) Display first 3 rows from the dataset:")
print(first_three_rows)
