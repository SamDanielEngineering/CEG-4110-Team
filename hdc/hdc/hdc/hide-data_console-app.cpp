#include <iostream>
#include <string>
#include <regex>

#include <fstream>
#include <opencv2/opencv.hpp>

#include "patient_medical_data.h"
#include "hide-data.h"
#include "hide-data_tests.h"

using namespace std;

PatientMedicalData record;

enum class Option
{
    name,
    age,
    social,
    gender,
    temperature,
    pulseRate,
    respirationRate,
    bloodPressureSystolic,
    bloodPressureDiastolic,
    healthHistory,
    currentHealthConditions,
    undefined
};

// It is possible to do sanity check on values,
// For example checking if name is over max string size or age over/under max/min value.
Option getOption(string str)
{
    if (str == "-n")
        return Option::name;
    if (str == "-a")
        return Option::age;
    if (str == "-s")
        return Option::social;
    if (str == "-g")
        return Option::gender;
    if (str == "-t")
        return Option::temperature;
    if (str == "-pr")
        return Option::pulseRate;
    if (str == "-rr")
        return Option::respirationRate;
    if (str == "-bps")
        return Option::bloodPressureSystolic;
    if (str == "-bpd")
        return Option::bloodPressureDiastolic;
    if (str == "-hh")
        return Option::healthHistory;
    if (str == "-hc")
        return Option::currentHealthConditions;
    return Option::undefined;
}

// reads string and returns vector of uint8_t that represent history
vector<uint8_t> getHistory(string str)
{
    vector<uint8_t> v;
    regex reg("(\"[0-9]\"|[0-9]+)");
    smatch match;
    while (regex_search(str, match, reg))
    {
        // cout << "match: " << match[1] << '\n';
        v.push_back(stoi(match[1], nullptr, 10));
        str = match.suffix();
    }
    return v;
}

// parses string and sets value of first option, return rest of string. 
string runOption(string str)
{ // does one option at a time and returns
    smatch match;
    regex valueRegex("(\"[a-zA-Z0-9 ]*\"|[^ ]+)");

    regex_search(str, match, valueRegex);
    Option option = getOption(match[1]);
    str = match.suffix(); // rest of string

    regex_search(str, match, valueRegex);
    string value = match[1];
    value.erase(remove(value.begin(), value.end(), '\"'), value.end()); //remove quotes
    str = match.suffix();

    switch (option)
    {
    case Option::name:
        record.name(value);
        break;
    case Option::age:
        record.age( stoi(value, nullptr, 10));
        break;
    case Option::social:
        record.social(stoi(value, nullptr, 10));
        break;
    case Option::gender:
        record.gender(value);
        break;
    case Option::temperature:
        record.temperature(stoi(value, nullptr, 10));
        break;
    case Option::pulseRate:
        record.pulseRate(stoi(value, nullptr, 10));
        break;
    case Option::respirationRate:
        record.respirationRate(stoi(value, nullptr, 10));
        break;
    case Option::bloodPressureSystolic: //
        record.bloodPressureSystolic(stoi(value, nullptr, 10));
        break;
    case Option::bloodPressureDiastolic: //
        record.bloodPressureDiastolic(stoi(value, nullptr, 10));
        break;
    case Option::healthHistory:
        record.healthHistory(getHistory(value));
        break;
    case Option::currentHealthConditions:
        record.currentHealthConditions(getHistory(value));
        break;
    default:
        cout << "not valid option:\n";
        str = ""; //empty string
        break;
    }
    return str; // returns string without consumed option and value
}


void resetValues()
{
    record.clear();
};

int HideDataConsoleApp(int argc, char** argv)
{

    if (argc == 1)
    {
        cout << "**** HideData ****\n";
        cout << "No arguments where given.\n";
        cout << "No documentation at this time, please provide arguments.\n";
    }
    else if (argc == 2)
    {
        ifstream file(argv[1]); // read data from text file
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                string currentLine = line.c_str();
                while (currentLine != "")
                {
                    currentLine = runOption(currentLine);
                }
                hide_data_tests::checks(record);
                record.validate();
                resetValues();
            }
            file.close();
        }
        else {
            cout << "file failed to open, make sure file path and name is correct. \n";
        }
        // readfile and parse
    }
    else
    {
        cout << "Only takes filename at this time, too many arguments given.\n";
    }

    return 0;
}

void HideDataTests() {
    cv::Mat targetImage = cv::imread("../image.jpg", cv::IMREAD_GRAYSCALE);
    PatientMedicalData patient = PatientMedicalData("First Last", "M", 22, 0);
    cv::Mat image = hide_data::encode(patient, targetImage);
    PatientMedicalData decodedPatient = hide_data::decode(image);
    cout << decodedPatient.name() << "\n";
    decodedPatient.validate();
    if (!image.empty()) {
        cv::imshow("", image);
    }
    else { cout << "Image not found"; }
    int k = cv::waitKey(0); // Wait for any keystroke in the window    
}

int main(int argc, char** argv)
{
    //HideDataConsoleApp(argc, argv);

    HideDataTests();

    return 0;
}