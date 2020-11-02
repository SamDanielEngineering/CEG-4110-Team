#ifndef HDC_HOSDATA_H_
#define HDC_HOSDATA_H_

#include <iostream>
#include <string>
#include <vector>

struct hosData
{
	std::string name, gender;
	uint8_t age, temperature, respirationRate, bloodPressureSystolic, bloodPressureDiastolic, pulseRate;
	uint32_t social;
	std::vector<uint8_t> currentHealthConditions, healthHistory;
};

#endif  // HDC_TESTS_H_