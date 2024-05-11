#include <iostream>

using namespace std;

string GetKeypadChars(int number)
{
  switch (number)
  {
  case 1:
    return ".*@";
  case 2:
    return "abc";
  case 3:
    return "def";
  case 4:
    return "ghi";
  case 5:
    return "jkl";
  case 6:
    return "mno";
  case 7:
    return "pqrs";
  case 8:
    return "tuv";
  case 9:
    return "wxyz";
  default:
    return "";
  }
}

void PrintKeypadCombinations(int input, string output)
{
  if (input < 10)
  {
    string charsForCurrentDigit = GetKeypadChars(input);

    for(int i = 0; i < charsForCurrentDigit.size(); ++i)
    {
      cout << charsForCurrentDigit[i] + output << endl;
    }

    return;
  }
  else
  {
    int smallerNumber = input / 10;
    int currentDigit = input % 10;

    string charsForCurrentDigit = GetKeypadChars(currentDigit);

    // Don't include current digit's corresponding characters
    PrintKeypadCombinations(smallerNumber, output);

    // Include current digit's corresponding characters
    for(int i = 0; i < charsForCurrentDigit.size(); ++i)
    {
      PrintKeypadCombinations(smallerNumber, charsForCurrentDigit[i] + output);
    }
  }
}

int main(int argc, char const *argv[])
{
  int number;
  cin >> number;

  PrintKeypadCombinations(number, "");

  return 0;
}
