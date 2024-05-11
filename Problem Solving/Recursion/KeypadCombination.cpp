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

int FindKeypadCombinations(int input, string output[])
{
  if (input < 10)
  {
    string charsForCurrentDigit = GetKeypadChars(input);

    for(int i = 0; i < charsForCurrentDigit.size(); ++i)
    {
      output[i] = charsForCurrentDigit[i];
    }

    return charsForCurrentDigit.size();
  }
  else
  {
    int smallerNumber = input / 10;

    int smallerNumberCombinationCount = FindKeypadCombinations(smallerNumber, output);

    int currentDigit = input % 10;

    string charsForCurrentDigit = GetKeypadChars(currentDigit);

    int k = 0;
    for(int i = 0; i < charsForCurrentDigit.size(); ++i)
    {
      for(int j = 0; j < smallerNumberCombinationCount; ++j)
      {
        output[smallerNumberCombinationCount + k] = output[j] + charsForCurrentDigit[i];
        ++k;
      }
    }

    // We could also write "return smallerNumberCombinationCount + k";
    return smallerNumberCombinationCount + (smallerNumberCombinationCount * charsForCurrentDigit.size());
  }
}

int main(int argc, char const *argv[])
{
  int number;

  cin >> number;

  // We're taking an arbitrary size of 1000.
  string* output = new string[1000];

  int count = FindKeypadCombinations(number, output);

  for(int i = 0; i < count; ++i)
  {
    cout << output[i] << "\n";
  }

  // Don't forget to clear dynamically allocated memory.
  delete [] output;

  return 0;
}
