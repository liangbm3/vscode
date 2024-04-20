import cv2
import numpy as np
image=cv2.imread("image2.png")
cv2.imshow("example",image)
print(image.shape)
# cv2.waitKey(0)
img=np.zeros((len(image),len(image[0])))
with open("1.txt","w",encoding="utf-8") as fp:
    print(len(image))
    print(len(image[0]))
    print(len(image[0][0]))
    for i in range(len(image)):
        for j in range(len(image[0])):
                total=0
                for k in range(len(image[0][0])):
                    total+=image[i][j][k]
                mean=total/3
                if mean>128:
                    mean=256
                else:
                    mean=0
                fp.write(str(mean)+" ")
                img[i,j]=mean
        fp.write("\n")
print(img)
cv2.imshow("aa",img)
cv2.waitKey(0)
