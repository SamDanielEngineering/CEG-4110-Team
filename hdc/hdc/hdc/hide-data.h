#ifndef HDC_HIDEDATA_H_
#define HDC_HIDEDATA_H_

#include <opencv2/opencv.hpp>

#include "patient_medical_data.h"

namespace hide_data
{
	cv::Mat encode(PatientMedicalData record, cv::Mat targetImage);
	PatientMedicalData decode(cv::Mat targetImage);
};

#endif  // HIDEDATA