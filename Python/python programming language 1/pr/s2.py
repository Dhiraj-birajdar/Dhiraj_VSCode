# #Q1. (1)
from math import pi
def vol(r):
    return ((4/3)*pi*r**3)
print(vol(7))

# # (2)
string1,string2="Hello ","World!"
print(string1 + string2)
string1,string2="Good ","Morning"
print(string1 + string2)

# # (3)
for i in range(20,31):
    print(i,i**i)

#Q2. (1)
def f(x):
    return x**2-5*x+6
print(f(-2),f(0),f(2))

# # (2)
def f(x):
    return x**3+5*x
print(f(10))

# (3)
from sympy import*
a = Matrix([[4,2,2],[2,4,2],[2,2,4]])
print(a.eigenvals())
print(a.eigenvects())