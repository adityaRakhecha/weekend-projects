#
 # 	meanFilter.py
 # 
 # 		Author:	Aditya Rakhecha
 #
 # 
 #
 # 	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 # 	Implement a mean filter with varying mask sizes
 #	to denoise the image
 #	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 #


import cv2 as cv
import numpy as np
import argparse as arg

#~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
#~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

#Create a parser (container/object)
parser = arg.ArgumentParser('Median Filter')

#Add argumnets to the container
parser.add_argument("-i", "--image", required = True,  metavar = '', help = "Input Image Path")
parser.add_argument("-s", "--size", required = True,  metavar = '', help = "Size of Mask", type = int)
args = parser.parse_args()

#~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
#~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

cv.namedWindow('Original Image', cv.WINDOW_AUTOSIZE)
cv.namedWindow('Filtered Image', cv.WINDOW_AUTOSIZE)
cv.moveWindow('Filtered Image' , 290, 60)
img = cv.imread(args.image, 0)
cv.imshow('Original Image', img)

#~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
#~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

def mean(k):
	sm = 0
	for i in range(1, len(k)):
		sm = sm + k[i]
	return sm/len(k)

#~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
#~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

msize = args.size
k = img[:]
mask=[img[0,0]]*(msize*msize)
irows = img.shape[0]
icolumns = img.shape[1]

for m in range(irows):
	for n in range(icolumns):
		for i in range(msize):
			for j in range(msize):
				if (m+i<irows and n+j<icolumns):
					mask[(i*msize) + j] = img[m+i, n+j]
	
		k[m,n] = mean(mask)
		
cv.imshow('Filtered Image', k)
cv.waitKey(0)
cv.destroyAllWindows()
