#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct StudentResult
{
    std::string studentName;
    int totalScore = 0;
};

void printResult(std::vector<StudentResult> &results)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "|"
              << std::setw(15)
              << "Student Name"
              << "|"
              << std::setw(15)
              << "Result" << "|"
              << std::endl;
    std::cout << "---------------------------------" << std::endl;

    for (StudentResult &result : results)
    {
        std::cout << "|"
                  << std::setw(15)
                  << result.studentName
                  << "|"
                  << std::setw(15)
                  << result.totalScore << "|"
                  << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }
}

int main()
{
    std::ifstream examDataFile("input.txt", std::ios::in);

    if (!examDataFile)
    {
        std::cerr << "Failed to open input file." << std::endl;
    }
    else
    {
        // First line of the file contains the correct answers
        std::string correctAnswers;
        std::getline(examDataFile, correctAnswers);

        std::vector<StudentResult> results;

        std::string line;
        while (std::getline(examDataFile, line))
        {
            // Fetching the student name line
            StudentResult newResult;
            newResult.studentName = line;

            // Fetching the student answers line
            std::getline(examDataFile, line);
            for (size_t i = 0; i < line.length(); i++)
            {
                if (correctAnswers[i] == line[i])
                {
                    newResult.totalScore++;
                }
            }

            results.push_back(newResult);
        }

        printResult(results);

        // for (StudentResult result : results)
        // {
        //     std::cout << result.studentName << std::endl;
        //     std::cout << result.totalScore << std::endl;
        //     std::cout << std::endl;
        // }
    }

    examDataFile.close();

    return 0;
}