import numpy as np
import cv2
import matplotlib.pyplot as plt
def rgb2gray(image):
    image_shape=image.shape
    gray_image=np.zeros((image_shape[0],image_shape[1]),dtype=np.uint8)
    for i in range(image_shape[0]):
        for j in range(image_shape[1]):            
            gray_image[i,j]=round(0.11*image[i,j,0]+0.59*image[i][j][1]+0.3*image[i][j][2])
    return gray_image
image=cv2.imread("image.png")
cv2.imshow("image",image)
gray_image=rgb2gray(image=image)
cv2.imshow("gray",gray_image)

def Pixel_num(img):
    num = [0 for _ in range(256)]
    a = np.shape(img)
    for i in range(a[0]):
        for j in range(a[1]):
            num[img[i][j]] += 1
    return num

def Pixel_rate(num_list):
    rate_list = []
    n = sum(num_list)
    for i in range(len(num_list)):
        rate = num_list[i] / n
        rate_list.append(rate)
    return rate_list
def Optimal_partition(rate_list):
    deltaMax = 0
    T = 0
    for i in range(256):
        w1 = w2 = u1 = u2 = 0
        u1tmp = u2tmp = 0
        deltaTmp = 0
        for j in range(256):
            if (j <= i):
                w1 += rate_list[j]
                u1tmp += j * rate_list[j]
            else:
                w2 += rate_list[j]
                u2tmp += j * rate_list[j]
        if w1 == 0:
            u1 = 0
        else:
            u1 = u1tmp / w1
        if w2 == 0:
            u2 = 0
        else:
            u2 = u2tmp / w2
        deltaTmp = w1 * w2 * ((u1- u2) ** 2)
        if deltaTmp > deltaMax:
            deltaMax = deltaTmp
            T = i
    return T
def Otsu(img, T):
    a = np.shape(img)
    new_img = np.zeros((a[0], a[1]))
    for i in range(a[0]):
        for j in range(a[1]):
            if img[i][j] > T:
                new_img[i][j] = 255
            else:
                new_img[i][j] = 0
    return new_img
num=Pixel_num(gray_image)
rate=Pixel_rate(num_list=num)
T=Optimal_partition(rate)
bit_image=Otsu(gray_image,T)
cv2.imshow("bit",bit_image)
cv2.waitKey(0)