// 	negativeTransformation.cpp

// 	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
// 	Program to get Negative Image of the input image
//	~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*


#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*


//Implementation details of Negative Transformation(setting up LUT)
vector<uchar> getNegativeLUT(){
	vector<uchar> LUT(256, 0);
	for(int i = 0; i < 256; ++i)
		LUT[i] = (uchar)(255 - i);
	return LUT;
}

//Using LUT in function
void TransformImage(Mat& I){
	vector<uchar> LUT = getNegativeLUT();
	for(int i = 0; i < I.rows; ++i){
		for(int j = 0; j < I.cols; ++j)
			I.at<uchar>(i, j) = LUT[I.at<uchar>(i, j)];
	}
}
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

int main(){
	
	//Read Image
	Mat inpImg = imread("image.jpg");
	Mat image;
	cvtColor(inpImg, image, CV_RGB2GRAY);

	
	//Copy Image
	Mat process_image = image.clone();
	
	//Transformation Function
	TransformImage(process_image);
	
	imshow("Original Image", inpImg);
	imshow("Transformed Image", process_image);
	
	waitKey(0);
	
	return 0;
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
