# counting black dots

With this program we can count and print the total number of black dots in an image.
The program uses numpy, argparse and cv2 modules. This is a basic Opencv program to learn the basic working of argparse
(for command line arguments) and functions cv.findContours() and cv.drawContours(). 

Click here to know more about [argparse](https://docs.python.org/3/library/argparse.html) and [contours](https://docs.opencv.org/3.4/d4/d73/tutorial_py_contours_begin.html).

## Input Image :

![dots](https://user-images.githubusercontent.com/25251763/40195475-2d4adb92-5a2b-11e8-9355-e394389dd9e0.jpg)

## Output Images :

### Modified

![screenshot from 2018-05-17 23-40-04](https://user-images.githubusercontent.com/25251763/40195633-acb451c4-5a2b-11e8-9055-6bb438d65738.png)

As you can see, all the black dots in the original image are now white on a black background.

### Infected

![screenshot from 2018-05-17 23-41-45](https://user-images.githubusercontent.com/25251763/40195699-e2e4933a-5a2b-11e8-8a74-365e354587bb.png)

As you can see, we have clearly found all the black dots in the image.

### Terminal

![screenshot from 2018-05-17 23-59-38](https://user-images.githubusercontent.com/25251763/40196527-71fb1a74-5a2e-11e8-8809-a43aa09d1e83.png)

As you can see, we have clearly count total number of black dots.

+ Moreover, the same concept can be used to detect, count or analyse dots, shapes or object of any colour in an image or video and concept of perspective 
tranformation can be added to add another feature to the program. 
