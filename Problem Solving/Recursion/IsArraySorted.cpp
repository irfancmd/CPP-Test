#include <iostream>

using namespace std;

bool IsSorted(int arr[], int size)
{
  // Array with 1 element is considered to be sorted
  if(size == 1) return true;

  if(arr[0] > arr[1])
  {
    return false;
  }
  else
  {
    // We know that"arr" is just a pointer to the first element.
    // So, by incrementing arr by 1, we can move the arr pointer to next
    // elements in each call. So when we'll be at second function call, arr[0] will
    // actually point to the second element and so on.
    return IsSorted(arr + 1, size - 1);
  }
}

int main(int argc, char const *argv[])
{

  int a[5] {1, 2, 4, 3, 5};

  bool result = IsSorted(a, 5);

  if(result)
  {
    cout << "The array is sorted.\n";
  }
  else
  {
    cout << "The array is not sorted.\n";
  }


  return 0;
}
