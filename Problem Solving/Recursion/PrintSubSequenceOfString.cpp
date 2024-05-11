#include <iostream>

using namespace std;

void PrintSubSequences(string input, string output)
{
  if(input.empty())
  {
    cout << output << "\n";
    return;
  }

  // Don't include current character in output
  PrintSubSequences(input.substr(1), output);
  // Include current character in output
  PrintSubSequences(input.substr(1), output + input[0]);
}

int main(int argc, char const *argv[])
{
  string input;
  cin >> input;

  PrintSubSequences(input, "");

  return 0;
}
