import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import MinMaxScaler

df=pd.read_csv('pre-processing.csv')
print(df.info())
print(df.head())

df.drop(['col1','col2','col3'],axis=1, inplace=True)
df=df.dropna()

X=df
y=df['cgpa']

le=LabelEncoder()
X['cgpa']=le.fit_transform(X['cgpa'])
y=le.transform(y)

ms=MinMaxScaler()
X=ms.fit_transform(X)

print(df.head())
