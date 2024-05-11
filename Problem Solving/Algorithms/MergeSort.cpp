#include <iostream>

using namespace std;

void MergeSort(int arr[], int start, int end)
{
  if(start >= end)
  {
    return;
  }

  int mid = start + ((end - start) / 2);

  MergeSort(arr, start, mid);
  MergeSort(arr, mid + 1, end);

  // Merge

  int sorted[end - start + 1];

  int i = start, j = mid + 1, k = 0;

  while (i <= mid && j <= end)
  {
    if(arr[i] < arr[j])
    {
      sorted[k] = arr[i];
      ++i;
    }
    else
    {
      sorted[k] = arr[j];
      ++j;
    }

    ++k;
  }

  while (i <= mid)
  {
    sorted[k] = arr[i];
    ++i;
    ++k;
  }

  while (j <= end)
  {
    sorted[k] = arr[j];
    ++j;
    ++k;
  }

  // Copy the sorted array elements back to main array
  for(int i = start, j = 0; i <= end; ++i)
  {
    arr[i] = sorted[j];
    ++j;
  }
}

int main(int argc, char const *argv[])
{
  int a1[] = { 5, 6, 23, 6, 2, 3, 6, 2, 1, 6, 34, 6 };

  int a1Length = 12;

  MergeSort(a1, 0, a1Length - 1);

  for(int i = 0; i < a1Length; ++i)
  {
    cout << a1[i] << " ";
  }

  cout << endl;

  return 0;
}
