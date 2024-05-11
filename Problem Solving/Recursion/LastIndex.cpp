#include <iostream>

using namespace std;

int LastIndex(int arr[], int size, int x)
{
  if(size == 0) return -1;

  int recursionResult = LastIndex(arr + 1, size - 1, x);

  if(recursionResult == -1 && arr[0] == x)
  {
    return 0;
  }

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

  int result = LastIndex(a, 7, 2);

  cout << result << endl;

  return 0;
}
