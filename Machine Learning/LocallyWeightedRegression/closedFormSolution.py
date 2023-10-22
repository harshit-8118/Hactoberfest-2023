import numpy as np
from numpy import linalg as lg
import matplotlib.pyplot as plt
from sklearn.datasets import make_regression

X, Y = make_regression(n_samples=400,n_features=1, n_informative=10, noise=1.8, random_state=11)
Y = Y.reshape((-1, 1))

# Normalize
X = (X - X.mean()) / X.std()
plt.scatter(X, Y)

ones = np.ones((X.shape[0], 1))
X = np.hstack((ones, X))
print(X.shape)
print(Y.shape)
# X.size() == (m, n + 1) = (400, 2)
# Y.size() == (m, 1) = (400, 1)

def predict(X, theta):
    return np.dot(X, theta)

def getThetaClosedForm(X, Y):
    xtransx = np.dot(X.T, X)
    xtransy = np.dot(X.T, Y)
    xtransxInv = lg.pinv(xtransx)
    theta = np.dot(xtransxInv, xtransy)
    return theta

theta = getThetaClosedForm(X, Y)
yPred = predict(X, theta)
print(theta)
# print(yPred)
plt.plot(X[:, 1], yPred, c='red', label='predicted line')
plt.legend()
plt.show()