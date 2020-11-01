#include <iostream>
#include <string.h>
#include <regex>

#include <fstream>

using namespace std;

string name, gender;
uint8_t age, temperature, respirationRate, bloodPressureSystolic, bloodPressureDiastolic, pulseRate;
uint32_t social;
vector<uint8_t> currentHealthConditions, healthHistory;

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

// This is a simple method for using switch statement with strings in C++. For an optimazed method, using constexpr to hash the string maybe preferred.
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
        name = value;
        break;
    case Option::age:
        age = stoi(value, nullptr, 10);
        break;
    case Option::social:
        social = stoi(value, nullptr, 10);
        break;
    case Option::gender:
        gender = value;
        break;
    case Option::temperature:
        temperature = stoi(value, nullptr, 10);
        break;
    case Option::pulseRate:
        pulseRate = stoi(value, nullptr, 10);
        break;
    case Option::respirationRate:
        respirationRate = stoi(value, nullptr, 10);
        break;
    case Option::bloodPressureSystolic: //
        bloodPressureSystolic = stoi(value, nullptr, 10);
        break;
    case Option::bloodPressureDiastolic: //
        bloodPressureDiastolic = stoi(value, nullptr, 10);
        break;
    case Option::healthHistory:
        healthHistory = getHistory(value);
        break;
    case Option::currentHealthConditions:
        currentHealthConditions = getHistory(value);
        break;
    default:
        cout << "not valid option:\n";
        str = ""; //empty string
        break;
    }
    return str; // returns string without consumed option and value
}

// For testing, prints out current values
void checks()
{
    cout << "*** Running Checks ***"
        "\n";
    if (!name.empty())
    {
        cout << "name: " << name << "\n";
    }
    else
    {
        cout << "name not set"
            << "\n";
    }

    if (age != 255)
    {
        cout << "age: " << (unsigned)age << "\n";
    }
    else
    {
        cout << "age not set"
            << "\n";
    }

    if (social < 1000000000)
    {
        cout << "social: " << (unsigned)social << "\n";
    }
    else
    {
        cout << "social not set"
            << "\n";
    }

    if (!gender.empty())
    {
        cout << "gender: " << gender << "\n";
    }
    else
    {
        cout << "gender not set"
            << "\n";
    }

    if (temperature != 255)
    {
        cout << "temperature: " << (unsigned)temperature << "\n";
    }
    else
    {
        cout << "temperature not set"
            << "\n";
    }

    if (pulseRate != 255)
    {
        cout << "pulseRate: " << (unsigned)pulseRate << "\n";
    }
    else
    {
        cout << "pulseRate not set"
            << "\n";
    }

    if (respirationRate != 255)
    {
        cout << "respirationRate: " << (unsigned)respirationRate << "\n";
    }
    else
    {
        cout << "respirationRate not set"
            << "\n";
    }

    if (bloodPressureSystolic != 255)
    {
        cout << "bloodPressureSystolic: " << (unsigned)bloodPressureSystolic << "\n";
    }
    else
    {
        cout << "bloodPressureSystolic not set"
            << "\n";
    }

    if (bloodPressureDiastolic != 255)
    {
        cout << "bloodPressureDiastolic: " << (unsigned)bloodPressureDiastolic << "\n";
    }
    else
    {
        cout << "bloodPressureDiastolic not set"
            << "\n";
    }

    if (size(healthHistory) != 0)
    {
        cout << "healthHistory: ";
        for (auto i : healthHistory) {
            std::cout << (unsigned)i << ' ';
        }

        cout << endl;
    }
    else
    {
        cout << "healthHistory not set"
            << "\n";
    }

    if (size(currentHealthConditions) != 0)
    {
        cout << "currentHealthConditions: ";
        for (auto i : currentHealthConditions) {
            std::cout << (unsigned)i << ' ';
        }
        cout << endl;

    }
    else
    {
        cout << "currentHealthConditions not set"
            << "\n";
    }
}

void resetValues()
{
    name = gender = "";
    age = temperature = social = respirationRate = bloodPressureDiastolic = bloodPressureSystolic = pulseRate = 255;
    currentHealthConditions.clear();
    healthHistory.clear();
};

int commandLineApplication(int argc, char** argv)
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
                checks();
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

int main(int argc, char** argv)
{
    commandLineApplication(argc, argv);
    return 0;
}