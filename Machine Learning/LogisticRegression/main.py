import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d

xtrainDf = pd.read_csv("LogisticRegression\Training Data\\xTrain.csv")
ytrainDf = pd.read_csv("LogisticRegression\Training Data\yTrain.csv")
print(xtrainDf.head())

xtrain = xtrainDf.values
ytrain = ytrainDf.values
# print(xtrain.shape)
# print(ytrain.shape)

ones = np.ones((xtrain.shape[0], 1))
xtrain = np.hstack((ones, xtrain))
xtrain


def sigmoid(z):
    return 1.0 / (1.0 + np.exp(-z))


def hypothesis(X, theta):
    y_ = sigmoid(np.dot(X, theta))
    return y_.reshape((-1, 1))


def error(X, Y, theta):
    y_ = hypothesis(X, theta)
    L = -np.mean(Y * np.log(y_) + (1 - Y) * np.log(1 - y_))
    return L


def gradient(X, Y, theta):
    y_ = hypothesis(X, theta)
    grad = -np.dot(X.T, (Y - y_))
    return grad / X.shape[0]


def gradientDescent(X, Y, alpha=0.1, maxIters=300):
    n = X.shape[1]
    theta = np.zeros((n, 1))
    errorlist = []
    for i in range(maxIters):
        grad = gradient(X, Y, theta)
        e = error(X, Y, theta)
        errorlist.append(e)
        theta = theta - alpha * grad

    return theta, errorlist


theta, errorlist = gradientDescent(xtrain, ytrain, maxIters=600)
print(theta)

plt.plot(errorlist)
plt.show()

xtestDf = pd.read_csv("LogisticRegression\Test Cases\\xTest.csv")

print(xtestDf.head())

xtest = xtestDf.values
ones = np.ones((xtest.shape[0], 1))
print(ones.shape)
xtest = np.hstack((ones, xtest))
print(xtest.shape)


def predict(X, theta):
    y_ = hypothesis(X, theta)
    output = np.zeros(y_.shape)
    output[y_ >= 0.5] = 1
    return output.astype("int")


y_pred = predict(xtest, theta)
print(y_pred)

y_pred = pd.DataFrame(y_pred, columns=["values"])
y_pred.head()
y_pred.to_csv("LogisticRegression\Test Cases\yPredicted.csv", index=False)


combinations = [(0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3)]

for feature_pair in combinations:
    plt.figure()
    x1, x2 = xtrain[:, feature_pair[0]], xtrain[:, feature_pair[1]]
    plt.scatter(x1[ytrain.flatten() == 0], x2[ytrain.flatten() == 0], label='Class 0', color='b')
    plt.scatter(x1[ytrain.flatten() == 1], x2[ytrain.flatten() == 1], label='Class 1', color='r')
    
    xx, yy = np.meshgrid(np.linspace(x1.min(), x1.max(), 100), np.linspace(x2.min(), x2.max(), 100))
    Z = sigmoid(theta[0] + theta[feature_pair[0]] * xx + theta[feature_pair[1]] * yy)
    plt.contour(xx, yy, Z, levels=[0.5], colors='green')
    
    plt.xlabel(f'Feature {feature_pair[0]}')
    plt.ylabel(f'Feature {feature_pair[1]}')
    plt.legend()
    plt.show()