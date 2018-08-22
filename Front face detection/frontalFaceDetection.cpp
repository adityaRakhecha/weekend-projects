#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

//Pre trained classifier for front face detection
String classifier = "haarcascade_frontalface_alt.xml";

int main(){
	//Read input image
	Mat inputImage = imread("grp2.jpg");
	//Make a copy of original
	Mat outputImage = inputImage.clone();

	//CascadeClassifier object
	CascadeClassifier frontFace_cascade;

	//load classifier
	frontFace_cascade.load(classifier);

	//vector to hold detected faces data
	vector<Rect> front_faces;

	frontFace_cascade.detectMultiScale(outputImage, front_faces, 1.1, 1, 0, Size(30,30));

	cout<< front_faces.size() << " faces detected...\n";

	//Draw bounded box for each detected face  
	for(int i =0; i < front_faces.size(); i++){
		Rect detected_face = front_faces[i];
		rectangle(outputImage, detected_face, Scalar(0, 0, 255), 2);

	}

	imshow("Input Image", inputImage);
	imshow("Faces detected", outputImage);
	waitKey(0);

	return 0;

}