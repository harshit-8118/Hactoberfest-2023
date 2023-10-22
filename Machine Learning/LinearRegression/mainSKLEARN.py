from sklearn import linear_model
from sklearn.datasets import make_regression
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

X, Y = make_regression(n_samples=1000, n_features=2, n_informative=1, noise=10, random_state=1)

# print(X, Y)
# plt.subplot(1, 2, 1)
# plt.scatter(X[:, 0], Y)
# plt.subplot(1, 2, 2)
# plt.scatter(X[:, 1], Y)
# plt.show()


fig = plt.figure()
axes = fig.add_subplot(projection='3d')
axes.scatter(X[:, 0], X[:, 1], Y)
plt.show()

model = linear_model.LinearRegression()

model.fit(X, Y)
print(model.coef_)
print(model.intercept_)

ypred = model.predict([X[0], X[1]])
print(ypred)

print(Y[0], Y[1])

print(model.score(X, Y))

X = pd.read_csv('LinearRegression\X_train.csv')
Y = pd.read_csv('LinearRegression\Y_train.csv')

model = linear_model.LinearRegression()

X = X.values
Y = Y.values
model.fit(X, Y)
print(model.coef_)
print(model.intercept_)
print(model.predict([X[0], X[1]]))
print(Y[0], Y[1])
print(model.score(X, Y))
'''
[[80.54593946]]
[3.72307244]
[[-19.57946526]
 [-43.70315254]]
[-0.09110112] [-53.46772085]
0.9709751195089489
'''

