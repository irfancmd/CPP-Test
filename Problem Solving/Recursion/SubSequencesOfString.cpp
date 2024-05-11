#include <iostream>
#include <math.h>

using namespace std;

int SubSequences(string input, string output[])
{
  if(input.empty())
  {
    output[0] = "";

    return 1;
  }

  string smallerString = input.substr(1);

  int smallerOutputSize = SubSequences(smallerString, output);

  for(int i = 0; i < smallerOutputSize; ++i)
  {
    output[smallerOutputSize + i] = input[0] + output[i];
  }

  // In each step, the output size doubles as we append current char to each of the
  // sub sequences found so far.
  return 2 * smallerOutputSize;
}

int main(int argc, char const *argv[])
{
  string input;
  cin >> input;

  // A string can have exactly (2 ^ n) subsequences INCLUDING EMPTY STRING.
  // This is because we have 2 choices (either take it or not take it) for each of the
  // 'n' number of characters.
  string* output = new string[(int)pow(2, input.size())];

  int count = SubSequences(input, output);

  for(int i = 0; i < count; ++i)
  {
    cout << output[i] << "\n";
  }

  // Don't forget to clear dynamically allocated memory.
  delete [] output;

  return 0;
}
