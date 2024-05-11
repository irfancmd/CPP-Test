#include <iostream>

using namespace std;

int FirstIndex(int arr[], int size, int x)
{
  if(size == 0) return -1;

  if(arr[0] == x)
  {
    return 0;
  }

  int recursionResult = FirstIndex(arr + 1, size - 1, x);

  if(recursionResult == -1)
  {
    return recursionResult;
  }
  else
  {
    return 1 + recursionResult;
  }
}

int main(int argc, char const *argv[])
{
  int a[] {5, 2, 3, 6, 3, 2, 5};

  int result = FirstIndex(a, 7, 6);

  cout << result << endl;

  return 0;
}
