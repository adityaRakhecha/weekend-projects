#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(){

	//Load Image
	Mat inpImage = imread("ironMan.jpg", 1);
	imshow("Input", inpImage);
	
	Mat outputImg = inpImage.clone();
	
	//Step 1: Apply Bilateral filter
	int i = 15;
	bilateralFilter(inpImage, outputImg, i, i*2, i/2);

	//Step 2: Convert Image to Grayscale
	cvtColor(outputImg, outputImg, COLOR_RGB2GRAY);

	//Step 3: Apply Median filter
	medianBlur(outputImg, outputImg, 5);
	

	//Step 4: Apply Adaptive thresholding
	adaptiveThreshold(outputImg, outputImg,255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,7,2);
	
	//Step5: Convert image to BGR
	cvtColor(outputImg, outputImg, COLOR_GRAY2RGB);
	
	//Step6: Apply bitwise AND operation
	Mat dstImg;
	bitwise_and(inpImage, outputImg, dstImg);
	
	//dstImg is our final Image
	imshow( "Output", dstImg);
	
	waitKey(0);
}
