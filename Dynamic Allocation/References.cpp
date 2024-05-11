#include <iostream>

using namespace std;

void foo1(const int& n);

int main(int argc, char const *argv[])
{
  /* One of the many features that C++ has over C, is references. */
  int i = 10;
  int& j = i; // j is an alias of 'i'.

  ++j;
  // Changing j changes i also
  cout << i << endl;

  foo1(i);

  return 0;
}

/*
  By taking parameters are reference, we can avoid unnecessary copy operations,
  and thus improve performance. If we don't want to change the thing the reference
  is referring to, we can mark the reference as "cosnt".
*/
void foo1(const int& n) {
  cout << "foo1() got n = " << n << endl;
}


/*
  However, it's not a good idea to return reference or pointer of a function's local
  variable, as that memory will be lost after going out of scope.
*/

// Bad practice
// int& foo2() {
//   int i = 10;

//   return i;
// }

// Bad practice
// int* foo3() {
//   int i = 10;

//   return &i;
// }
