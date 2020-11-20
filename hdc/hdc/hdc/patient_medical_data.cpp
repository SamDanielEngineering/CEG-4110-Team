#include "patient_medical_data.h"


PatientMedicalData::PatientMedicalData() {
    this->clear();
}

PatientMedicalData::PatientMedicalData(std::string name, unsigned char gender, uint8_t age, uint32_t social) {
    this->clear();

    this->name(name);
    this->gender(gender);
    this->age(age);
    this->social(social);
};

PatientMedicalData::PatientMedicalData(std::string name, unsigned char gender, uint8_t age, uint32_t social, uint8_t temperature, uint8_t respirationRate, uint8_t bloodPressureSystolic, uint8_t bloodPressureDiastolic, uint8_t pulseRate, unsigned char currentHealthCondition, std::string healthHistory) {
    this->name(name);
    this->gender(gender);
    this->age(age);
    this->temperature(temperature);
    this->respirationRate(respirationRate);
    this->bloodPressureSystolic(bloodPressureSystolic);
    this->bloodPressureDiastolic(bloodPressureDiastolic);
    this->pulseRate(pulseRate);
    this->social(social);
    this->currentHealthCondition(currentHealthCondition);
    this->healthHistory(healthHistory);
};

bool PatientMedicalData::validate() {
    bool val = true;
    //check name
    if (name().empty())
    {
        printf("Error: Name value is empty.\n");
        val = false;
    }else if(gender() == (char)"") //check gender
    {
        printf("Error: Gender value is empty.\n");
        val = false;
    }else if ( age() == std::numeric_limits<uint8_t>::max()) //check age
    {
        printf("Error: Age value is empty.\n");
        val = false;
    }else if ( social() == std::numeric_limits<uint32_t>::max()) //check social
    {
        printf("Error: Social value is empty.\n");
        val = false;
    }

    return val;
};

void PatientMedicalData::clear() {
    _name = "";
    _gender = (char)255;
    _age = std::numeric_limits<uint8_t>::max();
    _temperature = std::numeric_limits<uint8_t>::max();
    _social = std::numeric_limits<uint32_t>::max();
    _respirationRate = std::numeric_limits<uint8_t>::max();
    _bloodPressureDiastolic = std::numeric_limits<uint8_t>::max();
    _bloodPressureSystolic = std::numeric_limits<uint8_t>::max();
    _pulseRate = std::numeric_limits<uint8_t>::max();
    _currentHealthCondition = (char)255;
    _healthHistory = "";
};

std::string PatientMedicalData::name() { return _name; };
void PatientMedicalData::name(std::string newName) { _name = newName; };
unsigned char PatientMedicalData::gender() { return _gender; };
void PatientMedicalData::gender(unsigned char newGender) { _gender = newGender; };
uint8_t PatientMedicalData::age() { return _age; };
void PatientMedicalData::age(uint8_t newAge) { _age = newAge; };
uint8_t PatientMedicalData::temperature() { return _temperature; };
void PatientMedicalData::temperature(uint8_t newTemperature) { _temperature = newTemperature; };
uint8_t PatientMedicalData::respirationRate() { return _respirationRate; };
void PatientMedicalData::respirationRate(uint8_t newRespirationRate) { _respirationRate = newRespirationRate; };
uint8_t PatientMedicalData::bloodPressureSystolic() { return _bloodPressureSystolic; };
void PatientMedicalData::bloodPressureSystolic(uint8_t newBloodPressureSystolic) { _bloodPressureSystolic = newBloodPressureSystolic; };
uint8_t PatientMedicalData::bloodPressureDiastolic() { return _bloodPressureDiastolic; };
void PatientMedicalData::bloodPressureDiastolic(uint8_t newBloodPressureDiastolic) { _bloodPressureDiastolic = newBloodPressureDiastolic; };
uint8_t PatientMedicalData::pulseRate() { return _pulseRate; };
void PatientMedicalData::pulseRate(uint8_t newPulseRate) { _pulseRate = newPulseRate; };
uint32_t PatientMedicalData::social() { return _social; };
void PatientMedicalData::social(uint32_t newSocial) { _social = newSocial; };
unsigned char PatientMedicalData::currentHealthCondition() { return _currentHealthCondition; };
void PatientMedicalData::currentHealthCondition(unsigned char NewCurrentHealthConditions) { _currentHealthCondition = NewCurrentHealthConditions; };
std::string PatientMedicalData::healthHistory() { return _healthHistory; };
void PatientMedicalData::healthHistory(std::string newHealthHistory) { _healthHistory = newHealthHistory; };