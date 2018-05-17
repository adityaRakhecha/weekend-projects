#import neceesary packages
#numpy for numerical processing
import numpy as np

#argparse for parsing
import argparse as arg

#cv2 for Opencv
import cv2 as cv

#instantiating ArgumentParser object as 
ap = arg.ArgumentParser()

#adding arguments( both shortHand and longHand versions)
ap.add_argument("-i", "--image", help = "image name")

#turn the parsed command line arguments into a python dictionary
args = vars(ap.parse_args())

#load the image
image = cv.imread(args["image"])

#lower and upper range of black
#pure black
lower = np.array([0, 0, 0])

#dark shades of gray
upper = np.array([15, 15, 15])

#find all the black dots in the image
virus = cv.inRange(image, lower, upper)

# find the contours in the virus
(cnt, _) = cv.findContours(virus.copy(), cv.RETR_EXTERNAL,
	cv.CHAIN_APPROX_SIMPLE)
#print total number of dots 
print "I found %d black dots" % (len(cnt))

#modified image (black into white)
cv.imshow("Modified", virus)
 
# loop over the contours
for c in cnt:
	# draw all the contours with RED
	cv.drawContours(image, [c], -1, (0, 0, 255), 2)

#show contoured image
cv.imshow("Infected", image)
cv.waitKey(0)

#destroy both windows
cv.destroyAllWindows()
