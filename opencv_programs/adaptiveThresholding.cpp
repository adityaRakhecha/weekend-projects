//
// 	adaptiveThresholding.cpp
// 		Author:	Aditya Rakhecha
//
// 
//
// 	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
// 	Program to implement adaptive thresholding using normal mean on the input image
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
int mean(int *mask){
	int sum = 0;
	int length = sizeof(mask)/sizeof(*mask);
	for(int i = 0; i < length; i++)
		sum += mask[i];
	return sum/length;
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
Mat imageThreshold(Mat inputImage, uchar mSize, uchar maxVal, int type){
	Mat dstImage(inputImage.size(), inputImage.type());
	
	int height = inputImage.rows;
	int width = inputImage.cols;
	
	int mask[mSize * mSize]{0};
	int tval;

	for(int i = 0; i < height; i++){
		
		for(int j = 0; j < width; j++){
		
			for(int maskRow=0; maskRow<mSize; maskRow++)
			
				for(int maskCol=0; maskCol<mSize; maskCol++)
				
					if(i+maskRow < height && j+maskCol < width)

						mask[maskRow*mSize + maskCol] = inputImage.at<uchar>(i+maskRow, j+maskCol);
			//Calculate threshold	
			tval = mean(mask);
			
			if(type == 1)
				if(inputImage.at<uchar>(i , j) > tval)
					dstImage.at<uchar>(i, j) = maxVal;
				else
					dstImage.at<uchar>(i, j) = 0;
			
			else if(type == 2)
				if(inputImage.at<uchar>(i , j) > tval)
					dstImage.at<uchar>(i, j) = 0;
				else
					dstImage.at<uchar>(i, j) = maxVal;
		}
	}

	return dstImage;
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

int main(int argc, char *argv[]){

	if(argc != 5){
		cout<<"Give command line: 1.Image name 2.Block Size 3.Maximum Value and";
		cout<<"4. Type:: \n";
		cout<<"1 for Binary threshold\n";
		cout<<"2 for Inverted binary threshold\n";

		exit(0);
	}

	const char* filename;
	filename = argv[1];
	
	Mat inputImage = imread(filename, IMREAD_GRAYSCALE);

	if(inputImage.empty()){
	
		cout << "Can't load image" << endl;
		return -1;
	}

	imshow("Input image", inputImage);
	waitKey(0);

	if(atoi(argv[4]) > 2){
		cout<<"Wrong Type"<<"\n";
		exit(0);
	}

	// Convert string to integer
	int mSize = atoi(argv[2]);
	int maxVal = atoi(argv[3]);
	int type = atoi(argv[4]);	

	// Apply threshold function to the input image
	Mat Img = inputImage.clone();
	cout<<"thresholding...\n";
	Mat outputImage = imageThreshold(Img, mSize, maxVal, type);
	
	imshow("Threshold image", outputImage);
	waitKey(0);

	return 0;
}
