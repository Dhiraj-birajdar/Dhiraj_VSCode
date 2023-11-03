import pandas as pd
file = pd.read_csv("data.csv")
print("\n DATASET VALUES")
print("================")
print(file)
df = pd.DataFrame(file)
print("\n FREquency distribution")
print("======================")
data = df.groupby(['Gender','Result']).size().unstack().reset_index()
data['Total'] = (data['P'] + data['F'])
data['Pass_percent'] = data['P']/data['Total']
data['Fail_percent'] = data['F']/data['Total']
print(data[:5])