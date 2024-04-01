#include <iostream>
#include <fstream>
#include <cctype>
#include <climits>
#include <vector>
#include <map>
#include <sstream>

#define MAX_RED     12
#define MAX_GREEN   13
#define MAX_BLUE    14

int main()
{
    std::string strLine;
    std::ifstream ReadFile("../../2023/input2");
    std::stringstream ss;
    int nSumIdsOfPossibleGames = 0;

    bool bPossibleGame = true;
    int nGameId = 1;

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
            if ((v[i].find("red")   != std::string::npos) && (std::stoi(v[i-1]) > MAX_RED)   ||
                (v[i].find("green") != std::string::npos) && (std::stoi(v[i-1]) > MAX_GREEN) ||
                (v[i].find("blue")  != std::string::npos) && (std::stoi(v[i-1]) > MAX_BLUE))
            {
                bPossibleGame = false;
                break;
            }
        }

        if (bPossibleGame)
        {
            nSumIdsOfPossibleGames += nGameId;
        }

        bPossibleGame = true;
        nGameId++;
        ss = std::stringstream(); // clear the stringstream
    }

    std::cout << "Sum of the IDs of possible games: " << nSumIdsOfPossibleGames << std::endl;

    return 0;
}