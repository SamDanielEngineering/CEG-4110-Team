#include "hide-data_tests.h"

#include <iostream>

using namespace std;


void hide_data_tests::checks(PatientMedicalData record) {

    cout << "*** Running Checks ***"
        "\n";
    if (!record.name().empty())
    {
        cout << "name: " << record.name() << "\n";
    }
    else
    {
        cout << "name not set"
            << "\n";
    }

    if (record.age() != 255)
    {
        cout << "age: " << (unsigned)record.age() << "\n";
    }
    else
    {
        cout << "age not set"
            << "\n";
    }

    if (record.social() < 1000000000)
    {
        cout << "social: " << (unsigned)record.social() << "\n";
    }
    else
    {
        cout << "social not set"
            << "\n";
    }

    if (record.gender() != (char)255)
    {
        cout << "gender: " << record.gender() << "\n";
    }
    else
    {
        cout << "gender not set"
            << "\n";
    }

    if (record.temperature() != 255)
    {
        cout << "temperature: " << (unsigned)record.temperature() << "\n";
    }
    else
    {
        cout << "temperature not set"
            << "\n";
    }

    if (record.pulseRate() != 255)
    {
        cout << "pulseRate: " << (unsigned)record.pulseRate() << "\n";
    }
    else
    {
        cout << "pulseRate not set"
            << "\n";
    }

    if (record.respirationRate() != 255)
    {
        cout << "respirationRate: " << (unsigned)record.respirationRate() << "\n";
    }
    else
    {
        cout << "respirationRate not set"
            << "\n";
    }

    if (record.bloodPressureSystolic() != 255)
    {
        cout << "bloodPressureSystolic: " << (unsigned)record.bloodPressureSystolic() << "\n";
    }
    else
    {
        cout << "bloodPressureSystolic not set"
            << "\n";
    }

    if (record.bloodPressureDiastolic() != 255)
    {
        cout << "bloodPressureDiastolic: " << (unsigned)record.bloodPressureDiastolic() << "\n";
    }
    else
    {
        cout << "bloodPressureDiastolic not set"
            << "\n";
    }

    if (record.currentHealthCondition() != (unsigned char)255)
    {
        cout << "healthCondition: " << record.currentHealthCondition() << "\n";
    }
    else
    {
        cout << "healthCondition not set"
            << "\n";
    }

    if (record.healthHistory() != "")
    {
        cout << "healthHistory: " << record.healthHistory() << "\n";
    }
    else
    {
        cout << "healthHistory not set"
            << "\n";
    }
}
