import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


class NumberRecognizer:
    def __init__(self, trainPath, testPath) -> None:
        self.df = pd.read_csv(trainPath)
        # print(self.df.shape)
        # print(self.df.columns)

        self.data = self.df.values
        # print(self.data.shape)
        # print(type(self.data))

        self.X = self.data[:, 1:]
        self.Y = self.data[:, 0]
        self.trainingSize = self.X.shape[0]
        # print(self.X.shape)
        # print(self.Y.shape)

        self.df2 = pd.read_csv(testPath)
        # print(self.df2.shape)
        # print(self.df2.columns)

        self.testData = self.df2.values
        # print(self.testData.shape)

        self.testX = self.testData[:, 1:]
        self.testY = self.testData[:, 0]
        self.testSize = self.testX.shape[0]
        # print(self.testX.shape)
        # print(self.testY.shape)

        plt.figure(figsize=(10, 6))

    def drawImg(self):
        plt.show()

    def CollectImg(self, img, num, index):
        plt.subplot(5, 5, index + 1)
        plt.imshow(img.reshape(28, 28), cmap="gray")
        plt.title("Number : " + str(num))
        plt.axis("off")

    def dist(self, X1, X2):
        return np.sqrt(sum((X1 - X2) ** 2))

    def KNN(self, query, k=5):
        vals = []

        for i in range(self.trainingSize):
            d = self.dist(query, self.X[i])
            vals.append((d, self.Y[i]))

        vals = sorted(vals)[:k]
        frequent = [i[1] for i in vals]
        predictions, counts = np.unique(frequent, return_counts=True)
        mostFrequent = predictions[np.argmax(counts)]
        return mostFrequent


if __name__ == "__main__":
    trainPath = "practices/mnist_train.csv"
    testPath = "practices/mnist_test.csv"

    obj = NumberRecognizer(trainPath=trainPath, testPath=testPath)

    T = 5
    for i in range(T):
        predictedNumber = obj.KNN(obj.testX[i])
        print(predictedNumber)
        if predictedNumber == obj.testY[i]:
            print("prediction successfull!!")
        else:
            print("prediction failed!!")
        obj.CollectImg(obj.testX[i], obj.testY[i], i)

    obj.drawImg()


"""
## Training: 
trainingSize = 60k
imageSize = 28*28
training Complexity = O(1), we aren't training model so far..

## Testing:
testSize = 10k
Complexity=O(T * trainingSize * (784)) 
~ 28*28 -> 784
"""
