#include <iostream>
#include <fstream>
#include <cctype>

int main()
{
    std::string strLine;

    std::ifstream ReadFile("../../2023/input1");
    int nSumCalibrationValues = 0;
    bool bFound1stDigit = false, bFound2ndDigit = false;

    while (getline(ReadFile, strLine))
    {
        std::string str1stDigit = "", str2ndDigit = "";
        std::string strPossible1stDigit = "", strPossible2ndDigit = "";
        for (int i = 0; i < (strLine.length() / 2) + 1; i++)
        {
            if (isdigit(strLine[i]))
            {
                if (!bFound1stDigit)
                {
                    bFound1stDigit = true;
                    str1stDigit = strLine[i];
                }
                else if(bFound1stDigit && !bFound2ndDigit)
                {
                    strPossible2ndDigit = strLine[i];
                }
            }

            if((strLine.length() - i - 1) - i == 0 ? true : false)
            {
                // All characters were parsed on a line with odd number of characters
                break;
            }

            if(isdigit(strLine[strLine.length() - i - 1]))
            {
                if (!bFound2ndDigit)
                {
                    bFound2ndDigit = true;
                    str2ndDigit = strLine[strLine.length() - i - 1];
                }
                else if(bFound2ndDigit && !bFound1stDigit)
                {
                    strPossible1stDigit = strLine[strLine.length() - i - 1];
                }
            }

            if(bFound1stDigit && bFound2ndDigit)
            {
                break;
            }

            if((strLine.length() - i - 1) - i == 1 ? true : false)
            {
                // All characters were parsed on a line with even number of characters
                break;
            }
        }

        if(bFound1stDigit && bFound2ndDigit)
        {
            nSumCalibrationValues += std::stoi(str1stDigit + str2ndDigit);
        }
        else if (bFound1stDigit && !bFound2ndDigit && strPossible2ndDigit != "")
        {
            nSumCalibrationValues += std::stoi(str1stDigit + strPossible2ndDigit);
        }
        else if (!bFound1stDigit && bFound2ndDigit && strPossible1stDigit != "")
        {
            nSumCalibrationValues += std::stoi(strPossible1stDigit + str2ndDigit);
        }
        else if (bFound1stDigit && !bFound2ndDigit && strPossible2ndDigit == "")
        {
            nSumCalibrationValues += std::stoi(str1stDigit + str1stDigit);
        }
        else if (!bFound1stDigit && bFound2ndDigit && strPossible1stDigit == "")
        {
            nSumCalibrationValues += std::stoi(str2ndDigit + str2ndDigit);
        }

        bFound1stDigit = false;
        bFound2ndDigit = false;
    }

    std::cout << "Sum of calibration values: " << nSumCalibrationValues << std::endl;

    return 0;
}