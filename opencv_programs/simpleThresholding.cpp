//
// 	simpleThresholding.cpp
// 		Author:	Aditya Rakhecha
//
// 
//
// 	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
// 	Program to implement simple thresholding on the input image
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
Mat imageThreshold(Mat inputImage, uchar tval, uchar maxVal, int choice){

	Mat dstImage(inputImage.size(), inputImage.type());
	
	int height = inputImage.rows;
	int width = inputImage.cols;
	
	for(int i = 0; i < height; i++){
	
		for(int j = 0; j < width; j++){
	
			if(choice == 1)
	
				if(inputImage.at<uchar>(i , j) > tval)
					dstImage.at<uchar>(i, j) = maxVal;
	
				else
					dstImage.at<uchar>(i, j) = 0;
	
			else if(choice == 2)
	
				if(inputImage.at<uchar>(i , j) > tval)
					dstImage.at<uchar>(i, j) = 0;
	
				else
					dstImage.at<uchar>(i, j) = maxVal;
	
			else if(choice == 3)
	
				if(inputImage.at<uchar>(i , j) > tval)
					dstImage.at<uchar>(i, j) = tval;
	
				else
					dstImage.at<uchar>(i, j) = inputImage.at<uchar>(i , j);
	
			else if(choice == 4)
	
				if(inputImage.at<uchar>(i , j) > tval)
					dstImage.at<uchar>(i , j) = inputImage.at<uchar>(i , j);
	
				else
					dstImage.at<uchar>(i , j) = 0;
	
			else if(choice == 5)
	
				if(inputImage.at<uchar>(i , j) > tval)
					dstImage.at<uchar>(i , j) = 0;
	
				else
					dstImage.at<uchar>(i , j) = inputImage.at<uchar>(i , j);

		}
	}

	return dstImage;
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

int main(int argc, char *argv[]){

	if(argc != 5){
		cout<<"Give command line: 1.Image name 2.Threshold 3.Maximum Value and";
		cout<<"\n"<<"4. Choice:: ";
		cout<<"\n"<<"1 for Binary threshold";
		cout<<"\n"<<"2 for Inverted binary threshold";
		cout<<"\n"<<"3 for Truncate";
		cout<<"\n"<<"4 for Threshold-to-zero";
		cout<<"\n"<<"5 for Inverted threshold-to-zero";
		cout<<"\n";
		exit(0);
	}

	if(atoi(argv[4]) > 5){
		cout<<"Wrong Type"<<"\n";
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

	// Convert string to integer
	int tval = atoi(argv[2]);
	int maxVal = atoi(argv[3]);
	int choice = atoi(argv[4]);

	// Apply threshold function to the input image
	cout<<"thresholding...\n";
	Mat outputImage = imageThreshold(inputImage, tval, maxVal, choice);
	
	imshow("Threshold image", outputImage);
	waitKey(0);

	return 0;
}
