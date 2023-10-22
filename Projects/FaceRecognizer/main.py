import numpy as np
import cv2
import os
import math


def EucledianDistance(X1, X2):
    return np.sqrt(sum((X1 - X2) ** 2))


def KNN(train, test, k=10):
    m = train.shape[0]
    dists = []

    for i in range(m):
        ix = train[i, :-1]
        iy = train[i, -1]
        dist = EucledianDistance(ix, test)
        dists.append((dist, iy))

    dists = sorted(dists)[:k]
    topklabels = [i[1] for i in dists]
    labels, counts = np.unique(topklabels, return_counts=True)
    cluster = labels[np.argmax(counts)]
    # print("Cluster belongs to: ", cluster)
    return cluster


face_cascade = cv2.CascadeClassifier("Projects\FaceRecognizer\haarcascade_frontalface_alt.xml")

dataset_path = "Projects\FaceRecognizer\data\\"

face_data = []
labels = []
name = {}
offset = 10
class_id = 0

for file in os.listdir(dataset_path):
    if file.endswith(".npy"):
        name[class_id] = file[:-20]
        dataitem = np.load(dataset_path + file)
        # print(dataitem)
        face_data.append(dataitem)

        target = class_id * np.ones((dataitem.shape[0],))
        class_id += 1
        labels.append(target)

face_dataset = np.concatenate(face_data, axis=0)
face_labels = np.concatenate(labels, axis=0).reshape((-1, 1))

# print(face_data)
# print(labels)
# print(face_dataset)
# print(face_labels)
# print(face_dataset.shape)
# print(face_labels.shape)

trainset = np.int_(np.concatenate((face_dataset, face_labels), axis=1))
# print(trainset)
# print(trainset.shape)

cap = cv2.VideoCapture(0)
# exit(1)
while True:
    ret, frame = cap.read()

    if not ret:
        continue

    gray_image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(
        gray_image, 1.15, 5, flags=cv2.CASCADE_SCALE_IMAGE
    )

    for x, y, w, h in faces:
        face_section = frame[y - offset : y + h + offset, x - offset : x + w + offset]
        try:
            face_section = cv2.resize(face_section, (120, 120))

            out = KNN(trainset, face_section.flatten())

            predicted_name = str(name[int(out)])
            ind = predicted_name.rfind("_")
            if ind == -1:
                continue

            selfie_name = predicted_name[:ind]
            Gender = predicted_name[ind + 1 :]

            fontscale = min(w, h) * 0.007
            thickness = math.ceil(min(w, h) * 0.005)
            if Gender == "1":
                Gender = "Male"
            else:
                Gender = "Female"
            cv2.putText(
                frame,
                Gender,
                (x, y - 35),
                cv2.FONT_HERSHEY_SIMPLEX,
                fontscale,
                (51, 255, 255),
                thickness,
                cv2.LINE_AA,
            )
            cv2.putText(
                frame,
                selfie_name,
                (x, y - 10),
                cv2.FONT_HERSHEY_SIMPLEX,
                fontscale,
                (181, 255, 51),
                thickness,
                cv2.LINE_AA,
            )
            cv2.rectangle(
                frame,
                (x, y),
                (x + w, y + h),
                (42, 119, 246),
                2,
                cv2.CASCADE_SCALE_IMAGE,
            )
        except:
            continue

    cv2.imshow("Frames", frame)
    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()
