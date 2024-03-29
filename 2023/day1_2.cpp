#include <iostream>
#include <fstream>
#include <cctype>
#include <climits>
#include <vector>
#include <map>


std::vector<int> GetPositions(std::string strLine, std::string strSub)
{
    std::vector<int> vPositions;
    size_t nPos = strLine.find(strSub);
    while (nPos != std::string::npos)
    {
        vPositions.push_back(nPos);
        nPos = strLine.find(strSub, nPos + 1);
    }

    return vPositions;
}

int main()
{
    std::string strLine;
    std::vector <std::string> vListOfNumbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                                                    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::map<std::string, std::string> mNumberConversion = {{"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

    std::ifstream ReadFile("../../2023/input1");
    int nSumCalibrationValues = 0;
    bool bFound1stDigit = false, bFound2ndDigit = false;

    std::string str1stDigit = "", str2ndDigit = "";
    int dPos1stDigit = INT_MAX, dPos2ndDigit = -1; //overkill, but a simple way to initialize the variables

    while (getline(ReadFile, strLine))
    {
        for (auto number : vListOfNumbers)
        {
            std::vector<int> vPositions = GetPositions(strLine, number);
            if(vPositions.size() > 0)
            {
                if(vPositions[0] < dPos1stDigit)
                {
                    dPos1stDigit = vPositions[0];
                    str1stDigit = number;
                }
                if(vPositions[vPositions.size() - 1] > dPos2ndDigit)
                {
                    dPos2ndDigit = vPositions[vPositions.size() - 1];
                    str2ndDigit = number;
                }
            }
        }

        //Convert the spelled number to digit
        if(!isdigit(str1stDigit[0]))
        {
            str1stDigit = mNumberConversion[str1stDigit];
        }

        if(!isdigit(str2ndDigit[0]))
        {
            str2ndDigit = mNumberConversion[str2ndDigit];
        }

        if(str1stDigit != "" && str2ndDigit != "")
        {
            nSumCalibrationValues += std::stoi(str1stDigit + str2ndDigit);
        }

        str1stDigit = ""; str2ndDigit = "";
        dPos1stDigit = INT_MAX; dPos2ndDigit = -1;
    }

    std::cout << "Sum of calibration values: " << nSumCalibrationValues << std::endl;

    return 0;
}