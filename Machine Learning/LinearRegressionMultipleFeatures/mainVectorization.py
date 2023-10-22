from sklearn.datasets import load_diabetes
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import time

"""
CRIM - per capita crime rate by town
ZN - proportion of residential land zoned for lots over 25,000 sq.ft.
INDUS - proportion of non-retail business acres per town.
CHAS - Charles River dummy variable (1 if tract bounds river; 0 otherwise)
NOX - nitric oxides concentration (parts per 10 million)
RM - average number of rooms per dwelling
AGE - proportion of owner-occupied units built prior to 1940
DIS - weighted distances to five Boston employment centres
RAD - index of accessibility to radial highways
TAX - full-value property-tax rate per $10,000
PTRATIO - pupil-teacher ratio by town
B - 1000(Bk - 0.63)^2 where Bk is the proportion of blacks by town
LSTAT - % lower status of the population
MEDV - Median value of owner-occupied homes in $1000's
"""

housing = pd.read_csv("LinearRegressionMultipleFeatures\HousingData.csv")
# print(housing)
# print(housing.columns)
# print(housing.describe())

housing = housing.values
X = housing[:, :-1]
Y = housing[:, -1]

print(X.shape)
print(Y.shape)

# print(X)

# Normalise this dataset
# Each feature must have 0 mean, unit variance
mean = np.nanmean(X, axis=0)
std = np.nanstd(X, axis=0)
# print(mean)
# print(std)

# Normalised data
X = (X - mean) / std
# print(X)

ones = np.ones((X.shape[0], 1))
X = np.concatenate((ones, X), axis=1)
# print(X.shape)
# print(X[:, :])
X[np.isnan(X)] = 0


def hypothesis(x, theta):
    return np.dot(x, theta)


def error(X, Y, theta):
    m = X.shape[0]
    y_ = hypothesis(X, theta)
    jtheta = np.sum((y_ - Y) ** 2)

    return jtheta / m


def gradient(X, Y, theta):
    m = X.shape[0]
    y_ = hypothesis(X, theta)
    print(y_.shape)
    grad = np.dot(X.T, (y_ - Y))

    return grad / m


def gradient_descent(X, Y, learning_rate=0.1, max_epochs=300):
    n = X.shape[1]
    theta = np.zeros((n,))

    errorlist = []
    for i in range(max_epochs):
        e = error(X, Y, theta)
        errorlist.append(e)
        grad = gradient(X, Y, theta)
        theta = np.subtract(theta, learning_rate * grad)

    return theta, errorlist


start = time.time()
theta, errorlist = gradient_descent(X, Y)
# print(theta)
# print(errorlist)

end = time.time()
print("Time taken is: ", end - start)
plt.plot(errorlist)
plt.show()


y_predicted = hypothesis(X, theta)

def r2Score(Y, Y_):
    mean = np.mean(Y)
    sum1 = np.sum((Y - Y_) ** 2)
    sum2 = np.sum((Y - mean) ** 2)
    score = 1 - sum1 / sum2
    print(score * 100)


r2Score(Y, y_predicted)
