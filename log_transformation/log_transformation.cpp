//
// 	logTransformation.cpp
// 	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
// 	Program to implement Log Transformation of the input image
//	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

//Implementation details of Log Transformation(setting up LUT)
vector<uchar> getLogLUT(uchar maxValue){
	double C = 255 / log10(1 + maxValue);
	vector<uchar> LUT(256, 0);
	for(int i = 0; i<256; i++)
		LUT[i] = (int) round(C * log10(1 + i));
	return LUT;
}

//Using LUT in function
void TranformedImage(Mat& I){
	double maxValue;
	minMaxLoc(I, NULL, &maxValue);
	vector<uchar> LUT = getLogLUT((uchar) maxValue);
	for(int i = 0; i < I.rows; i++){
		for(int j = 0; j < I.cols; j++){
			I.at<uchar>(i, j) = LUT[I.at<uchar>(i, j)];
		}
	}
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*


int main(){
	
	//Read Image
	Mat image = imread("log.jpg", IMREAD_GRAYSCALE);
	
	//Copy Image
	Mat process_image = image.clone();

	//Transformation function
	TranformedImage(process_image);

	imshow("Original Image", image);
	imshow("Tranformed Image", process_image);

	waitKey(0);

	return 0;
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
