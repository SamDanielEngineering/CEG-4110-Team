#include "hosData.h"


bool hosData::validate() {

    return false; // placeholder
};
void hosData::clear() {
    _name = "";
    _gender = "";
    _age = 255;
    _temperature = 255;
    _social = 255;
    _respirationRate = 255;
    _bloodPressureDiastolic = 255;
    _bloodPressureSystolic = 255;
    _pulseRate = 255;
    _currentHealthConditions.clear();
    _healthHistory.clear();
};

std::string hosData::name() { return _name; };
void hosData::name(std::string) { std::string newName; };
std::string hosData::gender() { return _gender; };
void hosData::gender(std::string newGender) { _gender = newGender; };
uint8_t hosData::age() { return _age; };
void hosData::age(uint8_t newAge) { _age = newAge; };
uint8_t hosData::temperature() { return _temperature; };
void hosData::temperature(uint8_t newTemperature) { _temperature = newTemperature; };
uint8_t hosData::respirationRate() { return _respirationRate; };
void hosData::respirationRate(uint8_t newRespirationRate) { _respirationRate = newRespirationRate; };
uint8_t hosData::bloodPressureSystolic() { return _bloodPressureSystolic; };
void hosData::bloodPressureSystolic(uint8_t newBloodPressureSystolic) { _bloodPressureSystolic = newBloodPressureSystolic; };
uint8_t hosData::bloodPressureDiastolic() { return _bloodPressureDiastolic; };
void hosData::bloodPressureDiastolic(uint8_t newBloodPressureDiastolic) { _bloodPressureDiastolic = newBloodPressureDiastolic; };
uint8_t hosData::pulseRate() { return _pulseRate; };
void hosData::pulseRate(uint8_t newPulseRate) { _pulseRate = newPulseRate; };
uint32_t hosData::social() { return _social; };
void hosData::social(uint32_t newSocial) { _social = newSocial; };
std::vector<uint8_t> hosData::currentHealthConditions() { return _currentHealthConditions; };
void hosData::currentHealthConditions(std::vector<uint8_t> NewCurrentHealthConditions) { _currentHealthConditions = NewCurrentHealthConditions; };
std::vector<uint8_t> hosData::healthHistory() { return _healthHistory; };
void hosData::healthHistory(std::vector<uint8_t> newHealthHistory) { _healthHistory = newHealthHistory; };