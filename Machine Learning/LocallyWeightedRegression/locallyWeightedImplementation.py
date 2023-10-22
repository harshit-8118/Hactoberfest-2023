import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Locally Weighted Regression
# 1) Read and Normalise the Dataset
# 2) Generate W for every query point!
# 3) No training is involved, directly make predictions using closed form solution we dervied!
# (X'WX)inv * X'WY; where X' is X _ Transpose
# 4) Find the best value of Tau(Bandwidth Parameter) [Cross Validation]

df = pd.read_csv('LocallyWeightedRegression\\tips.csv')
# print(df.head())
data = df.values
# print(data)
# exit(1)
X = data[:, 0].reshape((-1, 1))
Y = data[:, 1].reshape((-1, 1))
# print(X)

# normalize()
X = (X- X.mean()) / X.std()
# plt.scatter(X, Y)
# plt.show()

# set W
def setW(queryPoint, X, tau):
    m = X.shape[0]
    W = np.mat(np.eye(m))
    
    x = queryPoint
    for i in range(m):
        xi = X[i]
        diff = xi - x
        val = -np.dot(diff, diff.T) / (2 * tau * tau)
        # print(val.item())
        W[i, i] = np.exp(val.item())
                   
    # print(W)
    return W

X = np.mat(X, dtype=np.float64)
Y = np.mat(Y, dtype=np.float64)
m = X.shape[0]


# setW(-1, X, 0.5)
# setW(-1, X, 1)
# setW(-1, X, 100)

ones = np.ones((m, 1), dtype=np.float64)
X_ = np.concatenate((X, ones), axis=1)
# print(X)
# print(type(X_))
# print(type(X))

def predict(X, Y, query_x, tau):
    query_x = np.mat([query_x, 1])

    W = setW(query_x, X, tau)
    xTWx = X.T * W * X
    # print(xTWx)

    xTWxinv = np.linalg.pinv(xTWx)
    # print(xTWxinv)
    # print(type(xTWxinv))
    xTWy = X.T * W * Y
    theta = xTWxinv * xTWy

    prediction = query_x * theta
    return theta, prediction

# theta, prediction = predict(X_, Y, 3, 1)
# print(theta)
# print(prediction)
# print(type(theta))

i = 1
def plotprediction(tau):
    x_test = np.linspace(-2, 4, 20)
    y_test = []

    for x in x_test:
        theta, prediction = predict(X_, Y, x, tau)
        y_test.append(prediction[0][0])

    y_test = np.array(y_test)
    xo = np.array(X)
    yo = np.array(Y)
    global i
    plt.subplot(3, 3, i)
    i += 1
    plt.scatter(xo, yo)
    plt.scatter(x_test, y_test, label=tau)
    plt.legend()


plotprediction(0.1)
plotprediction(0.3)
plotprediction(0.5)
plotprediction(0.7)
plotprediction(1)
plotprediction(25)
plotprediction(50)
plotprediction(75)
plotprediction(100)
plt.show()








