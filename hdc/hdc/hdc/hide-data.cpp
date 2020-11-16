#include "hide-data.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include "patient_medical_data.h"

using namespace std;

void encodePixels(uint8_t data, cv::Mat targetImage, int x, int y) {
	uint8_t mask = 1;
	for (int i = 0; i < 8; i++) {
		targetImage.at<uchar>(x+i, y) = ((targetImage.at<uchar>(x + i, y) & ~mask) | (data & mask));
		data = data >> 1;
	}

};

uint8_t decodePixels(cv::Mat targetImage, int x, int y) {
	uint8_t mask = 1;
	//uint8_t n = (arr[0] & mask) + ((arr[1] & mask) << 1) + ((arr[2] & mask) << 2) + ((arr[3] & mask) << 3) + ((arr[4] & mask) << 4) + ((arr[5] & mask) << 5) + ((arr[6] & mask) << 6) + ((arr[7] & mask) << 7);  // make sure all bits are zero
	uint8_t n = (targetImage.at<uchar>(x, y) & mask) +
				((targetImage.at<uchar>(x+1, y) & mask) << 1) +
				((targetImage.at<uchar>(x + 2, y) & mask) << 2) +
				((targetImage.at<uchar>(x + 3, y) & mask) << 3) +
				((targetImage.at<uchar>(x + 4, y) & mask) << 4) +
				((targetImage.at<uchar>(x + 5, y) & mask) << 5) +
				((targetImage.at<uchar>(x + 6, y) & mask) << 6) +
				((targetImage.at<uchar>(x + 7, y) & mask) << 7);
	return n;
};


void encodeName(std::string name, cv::Mat targetImage, int x, int y) {
	unsigned char nameAsChar[256] = {0};

	for (int i = 0; i < name.length(); i++) {
		nameAsChar[i] = name[i];
	}


	for (int i = 0; i < 2; i++) {  // I shifts the row
		for(int j = 0; j < 128; j++)
		encodePixels(nameAsChar[j+(128*i)], targetImage, x + (j*8), y+i);
	}
}

std::string decodeName(cv::Mat targetImage, int x, int y) {
	std::string name = "";

	for (int i = 0; i < 2; i++) {  // I shifts the row
		for (int j = 0; j < 128; j++)
			name += decodePixels(targetImage, x + (j * 8), y + i);
	}
	return name;
}


cv::Mat hide_data::encode(PatientMedicalData record, cv::Mat targetImage) {
	cv::Mat hiddenImage = targetImage.clone();

	// encode name
	encodeName(record.name(), hiddenImage, 0, 0);
	// encode gender
	encodePixels(record.gender(), hiddenImage, 0, 2); //have to skip a row because name takes up two

	return hiddenImage;
}


PatientMedicalData hide_data::decode(cv::Mat hiddenImage) {

	PatientMedicalData patient = PatientMedicalData();
	std::string hiddenName;
	hiddenName = decodeName(hiddenImage, 0, 0);
	patient.name(hiddenName);
	patient.gender((char)decodePixels(hiddenImage, 0, 2));
	return patient;
}
