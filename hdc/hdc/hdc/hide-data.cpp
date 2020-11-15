#include "hide-data.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include "patient_medical_data.h"

using namespace std;

cv::Mat hide_data::encode(PatientMedicalData record, cv::Mat targetImage) {
	//Example to show openv works 
	/*targetImage(cv::Rect(15, 15, 20, 40)) = 0;*/
	targetImage.at<uchar>(0, 0) = 'j';
	targetImage.at<uchar>(1, 0) = 'o';
	targetImage.at<uchar>(2, 0) = 'h';
	targetImage.at<uchar>(3, 0) = 'n';
	   return targetImage;
}


PatientMedicalData hide_data::decode(cv::Mat hiddenImage) {
	//Example to show openv works 
	//hiddenImage(cv::Rect(15, 15, 20, 40)) = 0;
	PatientMedicalData patient = PatientMedicalData();
	std::string name = "";
	name += hiddenImage.at<uchar>(0, 0); 
	name += hiddenImage.at<uchar>(1, 0);
	name += hiddenImage.at<uchar>(2, 0);
	name += hiddenImage.at<uchar>(3, 0);
	patient.name(name);
	return patient;
}
