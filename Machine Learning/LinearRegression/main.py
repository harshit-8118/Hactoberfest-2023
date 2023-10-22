import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


# download train test data

# load 
X = pd.read_csv('LinearRegression\X_train.csv')
Y = pd.read_csv('LinearRegression\Y_train.csv')

# visualize 
# plt.scatter(X, Y)
# plt.show()
X = X.values
Y = Y.values

# print(X)
# print(Y)
# Normalisation
mean = X.mean()
std = X.std()
X = (X - mean) / std

# plt.scatter(X, Y, c='orange')
# plt.title('Hardwork VS performance')
# plt.xlabel('Hardwork')
# plt.ylabel('Performance')
# plt.show()

'''
Implementation = Gradient Descent
'''
def hypothesis(x, theta):
    y_ = theta[0] + theta[1] * x
    return y_

def gradient(X, Y, theta):
    grad = np.zeros((2,))

    m = X.shape[0]
    for i in range(m):
        y_ = hypothesis(X[i], theta)
        x = X[i]
        y = Y[i]
        grad[0] += (y_ - y)
        grad[1] += ((y_ - y) * x)

    return (grad / m)

def gradientDescent(X, Y, alpha = 0.1):
    theta = np.zeros((2, ))
    steps = 100
    errorList = []
    thetalist = []
    for i in range(steps):
        grad = gradient(X, Y, theta)
        e = error(X, Y, theta)
        errorList.append(e)
        thetalist.append((theta[0], theta[1]))
        theta[0] = theta[0] - alpha * grad[0]
        theta[1] = theta[1] - alpha * grad[1]
    # print(theta)

    return theta, errorList, thetalist


# for checking if we actually minimising error or not J(theta) = ?
def error(X, Y, theta):
    m = X.shape[0]
    totalerr = 0.0

    for i in range(m):
        y_ = hypothesis(X[i], theta)
        totalerr += (y_ - Y[i]) ** 2

    return totalerr / m
        

theta, errorList, thetalist = gradientDescent(X, Y)

print(theta)
# [print(x) for x in errorList]
plt.plot(errorList)
print(min(errorList))
plt.show()
y_ = hypothesis(X, theta)
print(y_)

plt.scatter(X, Y, c='green')
plt.plot(X, y_, c='orange', label='predictionLine')
plt.title('Hardwork VS performance')
plt.xlabel('Hardwork')
plt.ylabel('Performance')
plt.legend()
plt.show()

X_test = pd.read_csv('LinearRegression\X_test.csv')
X_test = X_test.values
y_test = hypothesis(X_test, theta)
# print(y_test.shape)
# print(y_test)
df = pd.DataFrame(y_test, columns=['y'])
df.to_csv('LinearRegression\Y_predicted.csv', index=False)

# computing score 
sum1 = sum([(Y[i] - y_[i]) ** 2 for i in range(len(Y))])
Y_avg = Y.mean()
sum2 = sum([(Y[i] - Y_avg) ** 2 for i in range(len(Y))])

# or

sum1 = sum((Y - y_) ** 2)
sum2 = sum((Y - Y.mean()) ** 2)


r_square_score = 1 - sum1 / sum2
r_square_score *= 100
# print(r_square_score)

# error function visulization with random data
from mpl_toolkits.mplot3d import axes3d
t0 = np.arange(-50, 50, 1)
t1 = np.arange(20, 120, 1)

t0, t1 = np.meshgrid(t0, t1)

J = np.zeros(t0.shape)
for i in range(J.shape[0]):
    for j in range(J.shape[1]):
        y_ = t1[i, j] * X + t0[i, j]
        J[i, j] = np.sum((Y - y_) ** 2)/Y.shape[0]

print(J)
thetalist = np.array(thetalist)
# print(thetalist)
fig = plt.figure()
axes = fig.add_subplot(111, projection='3d')
axes.plot_surface(t0, t1, J, cmap='rainbow')
axes.scatter(thetalist[:, 0], thetalist[:,1], errorList, c='orange')
plt.show()
fig = plt.figure()
axes = fig.add_subplot(111, projection='3d')
axes.contour(t0, t1, J, cmap='copper')
axes.scatter(thetalist[:, 0], thetalist[:,1], errorList, c='orange')
# plt.plot(thetalist[:,0], label='theta0')
# plt.plot(thetalist[:,1], label='theta1')
plt.show()

# np.save('Thetalist.npy', thetalist)
