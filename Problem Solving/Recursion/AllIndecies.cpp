#include <iostream>

using namespace std;

int AllIndices(int arr[], int arrSize, int x, int output[])
{
  if(arrSize == 0) return 0;

  int recursionResult = AllIndices(arr + 1, arrSize - 1, x, output);

  // In each iteration, increment the values of output by 1 so that we get the
  // indecies of the whole array, not the portion that this recursive function sees.
  for(int i = 0; i < recursionResult; i++)
  {
    ++output[i];
  }

  if(arr[0] == x)
  {
    // Shift all elements of output by 1 place
    // The max size of output will be the same as arrSize, as an element cannot occur more
    // than arrSize times.
    for(int i = arrSize - 1; i > 0; --i)
    {
      output[i] = output[i - 1];
    }

    // Then put the index
    output[0] = 0;

    return 1 + recursionResult;
  }
  else
  {
    return recursionResult;
  }
}

// Simpler approach. Here, we take responsibility for checking the last elemnt
// instead of the first. This allows us to get rid of shifting and index increment steps
// that we had to do above.
int AllIndicesSimple(int arr[], int arrSize, int x, int output[])
{
  if(arrSize == 0) return 0;

  int recursionResult = AllIndices(arr, arrSize - 1, x, output);

  if(arr[arrSize - 1] == x)
  {
    output[recursionResult] = 0;

    return 1 + recursionResult;
  }
  else
  {
    return recursionResult;
  }
}



int main(int argc, char const *argv[])
{
  int a[] {5, 2, 3, 6, 3, 2, 5};

  int output[7];

  int result = AllIndices(a, 7, 3, output);

  cout << result << "\n";

  for(int i = 0; i < result; ++i)
  {
    cout << output[i] << " ";
  }

  cout << "\n";

  cout << "Simpler approach:\n";

  result = AllIndicesSimple(a, 7, 3, output);

  cout << result << "\n";

  for(int i = 0; i < result; ++i)
  {
    cout << output[i] << " ";
  }

  cout << "\n";

  return 0;
}
