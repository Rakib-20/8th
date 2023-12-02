from sklearn.datasets import load_iris
from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score

iris=load_iris()

data=iris.data
print(data[:5])

target=iris.target
print(target)

kmeans=KMeans(n_clusters=3)
kmeans.fit(data)

predicted_labels=kmeans.labels_

accuracy=accuracy_score(target, predicted_labels)
print(f'Accuracy: {accuracy}')

