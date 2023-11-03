import pandas as pd

# Sample data
data = {'Country': ['USA', 'Canada', 'UK', 'Germany', 'France'],
        'Purchased': ['Yes', 'No', 'Yes', 'No', 'Yes']}

# Create a DataFrame
df = pd.DataFrame(data)

# Apply One-Hot encoding to the 'Country' column
df = pd.get_dummies(df, columns=['Country'], prefix=['Country'])

# Apply Label encoding to the 'Purchased' column
df['Purchased'] = df['Purchased'].map({'Yes': 1, 'No': 0})

# Save the dataset to a CSV file
df.to_csv('datacountry.csv', index=False)
