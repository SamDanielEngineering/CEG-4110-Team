#include "hide-data.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include "patient_medical_data.h"

using namespace std;

void encodePixels8(uint8_t data, cv::Mat targetImage, int x, int y) {
	uint8_t mask = 1;
	for (int i = 0; i < 8; i++) {
		targetImage.at<uchar>(x+i, y) = ((targetImage.at<uchar>(x + i, y) & ~mask) | (data & mask));
		data = data >> 1;
	}

};//uint32_t

void encodePixels32(uint32_t data, cv::Mat targetImage, int x, int y) {
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		targetImage.at<uchar>(x + i, y) = ((targetImage.at<uchar>(x + i, y) & ~mask) | (data & mask));
		data = data >> 1;
	}

};//uint32_t

uint8_t decodePixels8(cv::Mat targetImage, int x, int y) {
	uint8_t mask = 1;

	uint8_t n=0;
	for (int i = 0; i < 8; i++) {
		n += ((targetImage.at<uchar>(x + i, y) & mask) << i);
	}
	return n;
};

uint32_t decodePixels32(cv::Mat targetImage, int x, int y) {
	uint32_t mask = 1;

	uint32_t n = 0;
	for (int i = 0; i < 32; i++) {
		n += ((targetImage.at<uchar>(x + i, y) & mask) << i);
	}

	return n;
};


void encodeName(std::string name, cv::Mat targetImage, int x, int y) {
	unsigned char nameAsChar[256] = {0};

	for (int i = 0; i < name.length(); i++) {
		nameAsChar[i] = name[i];
	}


	for (int i = 0; i < 2; i++) {  // I shifts the row
		for(int j = 0; j < 128; j++)
		encodePixels8(nameAsChar[j+(128*i)], targetImage, x + (j*8), y+i);
	}
}

std::string decodeName(cv::Mat targetImage, int x, int y) {
	std::string name = "";

	for (int i = 0; i < 2; i++) {  // I shifts the row
		for (int j = 0; j < 128; j++)
			name += decodePixels8(targetImage, x + (j * 8), y + i);
	}
	return name;
}


cv::Mat hide_data::encode(PatientMedicalData record, cv::Mat targetImage) {
	cv::Mat hiddenImage = targetImage.clone();

	// encode name
	encodeName(record.name(), hiddenImage, 0, 0);
	// encode gender
	encodePixels8(record.gender(), hiddenImage, 0, 2); //have to skip a row because name takes up two
	encodePixels8(record.age(), hiddenImage, 0, 3);
	encodePixels32(record.social(), hiddenImage, 0, 4);
	return hiddenImage;
}


PatientMedicalData hide_data::decode(cv::Mat hiddenImage) {

	PatientMedicalData patient = PatientMedicalData();
	std::string hiddenName;
	hiddenName = decodeName(hiddenImage, 0, 0);
	patient.name(hiddenName);
	patient.gender((char)decodePixels8(hiddenImage, 0, 2));
	patient.age(decodePixels8(hiddenImage, 0, 3));
	patient.social(decodePixels32(hiddenImage, 0, 4));
	return patient;
}
