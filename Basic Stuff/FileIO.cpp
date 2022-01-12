#include <iostream>
#include <fstream>
#include <iomanip>

bool isBlankLine(std::string &line)
{
    for (char &c : line)
    {
        if (std::isalpha(c) || std::isdigit(c) || std::ispunct(c))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::ifstream inputFile("RomeoAndJuliet.txt", std::ios::in);
    std::ofstream outputFile("NumberedNovel.txt");

    if (!inputFile)
    {
        std::cout << "Error occured while opening the file" << std::endl;
    }
    else if (!outputFile)
    {
        std::cout << "Error occured while creating the file" << std::endl;
    }
    else
    {
        unsigned int lineNumber = 1;
        std::string line;

        while (!inputFile.eof())
        {
            std::getline(inputFile, line);
            if (!isBlankLine(line))
            {
                outputFile << std::setw(5)
                           << std::right
                           << lineNumber << " " << line;
                lineNumber++;
            }
            else
            {
                outputFile << line;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}