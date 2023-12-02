import pandas as pd

data = {
        'Name':['Rakib','Raihan','Mehedi'],
        'Age':[23,24,25],
        'City':['Mymensingh','Trishal','Dhaka']
}
df=pd.DataFrame.from_dict(data)
print('Created data frame')
print(df)

df.to_csv('data.csv')
df.to_excel('data.xlsx')
df.to_json('data.json')

df=pd.read_csv('data.csv')
print('\n CSV file');
print(df)

df=pd.read_excel('data.xlsx')
print('\n Excel file')
print(df)

df=pd.read_json('data.json')
print('JSON file')
print(df)
