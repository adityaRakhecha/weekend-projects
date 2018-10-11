// 	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
// 	Program to implement median filter on the input image
//	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*


#include <stdio.h>
#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

Mat getPaddedImage(Mat image, int size){

	Mat dstImage(Size(image.cols+size-1, image.rows+size-1),image.depth(),image.channels());

	copyMakeBorder(image, dstImage, size/2, size/2, size/2, size/2, BORDER_REPLICATE);

	return dstImage;

}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

Mat medianFiltering(Mat image, int size){

	int height = image.rows;
	int width = image.cols;

	Mat dstImage = image.clone();

	int valuesArray[size * size]{0};

	for(int row=0; row<height; row++){
	
		for(int col=0; col< width; col++){
		
			for(int maskRow=0; maskRow<size; maskRow++){
			
				for(int maskCol=0; maskCol<size; maskCol++){
				
					if(row+maskRow < height && col+maskCol < width){
					
						valuesArray[maskRow * size + maskCol] = image.at<uchar>(row+maskRow, col+maskCol);
					}
				}
			}

			sort(valuesArray, valuesArray+(size*size));
			dstImage.at<uchar>(row+size/2, col+size/2) = valuesArray[(size*size)/2];
		}
	}

	return dstImage;
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

int main(int argc, char* argv[]){

	const char* filename;

	if(argc != 3){
		cout<<"Give command line: a.out [image name] [mask size 3 5 or 7]";
		exit(0);
	}

	filename = argv[1];

	// Convert string to integer
	int maskSize = atoi (argv[2]);

	Mat sourceImage = imread(filename, 0);

	imshow("image", sourceImage);
	waitKey(0);

	if(sourceImage.empty()){
	
		cout << "Can't load image" << endl;
		return -1;
	}

	int height = sourceImage.rows;
	int width = sourceImage.cols;

	// Create a padding so that filtering can be applied to
	// border pixels as well
	Mat paddedImage = getPaddedImage(sourceImage, maskSize);

	// Apply median filter to the padded image
	Mat medianFilteredImage = medianFiltering(paddedImage, maskSize);
	
	// Remove padding from the filtered image. You can check the
	// effect of padding by taking masking size as 9 or more
	Mat finalImage (medianFilteredImage, Rect(maskSize/2, maskSize/2, width, height));

	imshow("Filtered image with padding", medianFilteredImage);
	waitKey(0);

	imshow("Final Filtered image", finalImage);
	waitKey(0);

	return 0;
}
