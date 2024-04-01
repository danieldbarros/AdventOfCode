#include <iostream>
#include <fstream>
#include <cctype>
#include <climits>
#include <vector>
#include <map>
#include <sstream>

int main()
{
    std::string strLine;
    std::ifstream ReadFile("../../2023/input2");
    std::stringstream ss;
    int nSumIdsOfPossibleGames = 0;

    bool bPossibleGame = true;
    int nGameId = 1;

    int nMaxRed = 0, nMaxGreen = 0, nMaxBlue = 0;
    int nSumOfPowerOfSet = 0;

    while (getline(ReadFile, strLine))
    {
        ss << strLine;
        std::vector<std::string> v;
        while (ss.good())
        {
            std::string substr;
            getline(ss, substr, ' '); //separator is a space
            v.push_back(substr);
        }

        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i].find("red") != std::string::npos && std::stoi(v[i-1]) > nMaxRed)
                    nMaxRed = std::stoi(v[i-1]);
            else if (v[i].find("green") != std::string::npos && std::stoi(v[i-1]) > nMaxGreen)
                    nMaxGreen = std::stoi(v[i-1]);
            else if (v[i].find("blue") != std::string::npos && std::stoi(v[i-1]) > nMaxBlue)
                    nMaxBlue = std::stoi(v[i-1]);
        }

        nSumOfPowerOfSet += nMaxRed * nMaxGreen * nMaxBlue;

        nMaxRed = 0;
        nMaxGreen = 0;
        nMaxBlue = 0;
        ss = std::stringstream(); // clear the stringstream
    }

    std::cout << "Sum of the Power of sets: " << nSumOfPowerOfSet << std::endl;

    return 0;
}