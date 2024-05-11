#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  /*
    Unlike higher level languages like Java, C++ doesn't give us a direct way
    of creating multi-dimensional arrays like "new int[m][n]". Instead, we have
    to allocate memory for the subarrays manually.
  */
  int m, n;
  cin >> m >> n;

  int** matrix = new int*[m];

  for(int i = 0; i < m; ++i)
  {
    matrix[i] = new int[n];

    for(int j = 0; j < n; ++j) {
      printf("matrix[%d][%d] = ", i, j);
      cin >> matrix[i][j];
    }
  }

  cout << "The matrix is:\n";

  for(int i = 0; i < m; ++i)
  {
    for(int j = 0; j < n; ++j) {
      cout << matrix[i][j] << " ";
    }

    cout << "\n";
  }

  /*
    Just like we manually allocated memory for the sub-arrays, we also have to manually
    delete EACH OF THEM.
  */
  for(int i = 0; i < m; ++i)
  {
    delete [] matrix[i];
  }

  // Finally, we'll delete the parent array's memory.
  delete [] matrix;

  return 0;
}
