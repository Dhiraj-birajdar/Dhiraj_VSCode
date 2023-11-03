import pandas as pd
import scipy.stats as s
score = {"English":[67,78,78,79,43,68,90,89,49,71], "Science":[58,86,57,49,87,82,96,64,68,61]}
df = pd.DataFrame(score)
print(df)

print("Arithmetic mean: ",s.tmean(score["English"]))
print("Harmonic mean: ",s.hmean(score["English"]))
print("Geometric mean: ",s.gmean(score["English"]).round(2))
print("Median: ",df["English"].median())
print("Mode: ",df["English"].mode())
