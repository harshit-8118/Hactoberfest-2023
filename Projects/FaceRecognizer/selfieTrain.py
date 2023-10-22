import cv2
import numpy as np
import datetime

cap = cv2.VideoCapture(0)

face_cascade = cv2.CascadeClassifier("Projects\FaceRecognizer\haarcascade_frontalface_alt.xml")

Filename = input("Enter your name: ").strip()
Gender = input("Enter you Gender: ").strip()

if "F" in Gender or "f" in Gender:
    Gender = 0
else:
    Gender = 1

current_datetime = datetime.datetime.now()
date_time_string = current_datetime.strftime("%Y%m%d_%H%M%S")

Filename = f"{Filename}_{str(Gender)}_{date_time_string}"
# print(Filename)

facedata = []
dataset_path = "Projects\FaceRecognizer\data\\"
skip = 0
offset = 10

while True:
    ret, frame = cap.read()

    if not ret:
        continue

    gray_img = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    selfies = face_cascade.detectMultiScale(
        gray_img, 1.2, 5, flags=cv2.CASCADE_SCALE_IMAGE
    )
    # print(selfies)
    selfies = sorted(selfies, key=lambda f: f[2] * f[3], reverse=True)
    face = []
    for x, y, w, h in selfies:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (42, 119, 246), 2)
        # extract (crop out the required face) region of Interest
        face = frame[y - offset : y + h + offset, x - offset : x + w + offset]
        try:
            face = cv2.resize(face, (120, 120))
            skip += 1
            if skip % 10 == 0:
                facedata.append(face)
                print(len(facedata))
        except:
            continue

    cv2.imshow("Frames", frame)
    if len(face):
        cv2.imshow("Face section", face)

    keypressed = cv2.waitKey(1) & 0xFF
    if keypressed == ord("q"):
        break

facedata = np.asarray(facedata)
facedata = facedata.reshape((facedata.shape[0], -1))
# print(facedata.shape)

np.save(dataset_path + Filename + ".npy", facedata)
print("file saved successfully in " + dataset_path + Filename + ".npy")

cap.release()
cv2.destroyAllWindows()
