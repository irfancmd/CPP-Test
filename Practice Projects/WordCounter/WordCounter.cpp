#include <iostream>
#include <fstream>
#include <string>

int main()
{

    std::ifstream textFile("../RomeoAndJuliet.txt", std::ios::in);

    if(!textFile)
    {
        std::cerr << "Failed to open the file" << std::endl;
    }
    else
    {
        std::cout << "Enter a word to search: ";
        std::string word;
        std::cin >> word;

        int count = 0;
        std::string line;
        while(std::getline(textFile, line))
        {
            // Initially we start looking from the first character of the string
            size_t pos = line.find(word, 0);
            while(pos != std::string::npos)
            {
                count++;
                // We continue checking for the word after the position of the previously found match
                pos = line.find(word, pos + word.length());
            }
        }

        std::cout << "The word \"" << word << "\" occurs " << count << " times" << std::endl;
    }

    textFile.close();
    
    return 0;
}