import pandas as pd 
from mlxtend.frequent_patterns import apriori,association_rules
from mlxtend.preprocessing import TransactionEncoder

transactions = [['Bread','Milk'],
                ['Bread','Diaper','Beer','Eggs'],
                ['Milk','Diaper','Beer','Coke'],
                ['Bread', 'Milk','Diaper','Beer'],
                ['Bread' ,'Milk','Diaper','Coke']]

te = TransactionEncoder()
te_array = te.fit(transactions).transform(transactions)

df = pd.DataFrame(te_array , columns = te.columns_)

freq_items = apriori(df,min_support = 0.5
                      ,use_colnames=True)
print(freq_items)

rules = association_rules(freq_items,metric='support', min_threshold=0.05)
rules = rules.sort_values(['support','confidence'] , ascending=[False,False])

print(rules)