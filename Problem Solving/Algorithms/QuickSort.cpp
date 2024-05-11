#include <iostream>

using namespace std;

int Partition(int arr[], int start, int end)
{
  // We will always treat the first index as pivot, althrough there are more complex ways
  // to choose it for optimizaiton.
  int pivotIndex = start;

  int i = start + 1;

  for(int j = start + 1; j <= end; j++)
  {
    // Moving all elements smaller than the pivot to at the start of the array.
    if(arr[j] < arr[pivotIndex])
    {
      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;

      ++i;
    }
  }

  // Now, we're putting the pivot in the right place.
  int temp = arr[i - 1];
  arr[i - 1] = arr[start];
  arr[start] = temp;

  return i - 1;
}

void QuickSort(int arr[], int start, int end)
{
  if(start >= end)
  {
    return;
  }

  int partitionIndex = Partition(arr, start, end);

  QuickSort(arr, start, partitionIndex - 1);
  QuickSort(arr, partitionIndex + 1, end);
}

int main(int argc, char const *argv[])
{
  int a1[] = { 5, 6, 23, 6, 2, 3, 6, 2, 1, 6, 34, 6 };

  int a1Length = 12;

  QuickSort(a1, 0, a1Length - 1);

  for(int i = 0; i < a1Length; ++i)
  {
    cout << a1[i] << " ";
  }

  cout << endl;

  return 0;
}
