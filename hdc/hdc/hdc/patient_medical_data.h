#ifndef HDC_PATIENTMEDICALDATA_H_
#define HDC_PATIENTMEDICALDATA_H_

#include <iostream>
#include <string>
#include <vector>

class PatientMedicalData
{
private:
	std::string _name, _healthHistory;
	unsigned char _gender, _currentHealthCondition;
	uint8_t _age, _temperature, _respirationRate, _bloodPressureSystolic, _bloodPressureDiastolic, _pulseRate;
	uint32_t _social;
public:
	PatientMedicalData();
	PatientMedicalData(std::string name, unsigned char gender, uint8_t age, uint32_t social);
	PatientMedicalData(std::string name, unsigned char gender, uint8_t age, uint32_t social, uint8_t temperature, uint8_t respirationRate, uint8_t bloodPressureSystolic, uint8_t bloodPressureDiastolic, uint8_t pulseRate, unsigned char currentHealthCondition, std::string healthHistory);
	std::string name();
	void name(std::string newName);
	unsigned char gender();
	void gender(unsigned char newGender);
	uint8_t age();
	void age(uint8_t newAge);
	uint8_t temperature();
	void temperature(uint8_t newTemperature);
	uint8_t respirationRate();
	void respirationRate(uint8_t newRespirationRate);
	uint8_t bloodPressureSystolic();
	void bloodPressureSystolic(uint8_t newBloodPressureSystolic);
	uint8_t bloodPressureDiastolic();
	void bloodPressureDiastolic(uint8_t newBloodPressureDiastolic);
	uint8_t pulseRate();
	void pulseRate(uint8_t newPulseRate);
	uint32_t social();
	void social(uint32_t newSocial);
	unsigned char currentHealthCondition();
	void currentHealthCondition(unsigned char charNewCurrentHealthConditions);
	std::string healthHistory();
	void healthHistory(std::string newHealthHistory);
	bool validate();
	void clear();
};



#endif  // PATIENTMEDICALDATA