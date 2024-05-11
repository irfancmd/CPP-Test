#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int num = 65;

  int* numP = &num;
  char* chP = (char*) numP;

  // If we print an int pointer, it will print address
  //cout << numP << endl;
  // But, if we print char pointer, it will keep priting next bytes until it reaches a null character.
  //cout << chP << endl;

  /*
    Since int is 4 bytes and char is 1 byte, if we read the contents of (chP + 3), we should
    get 'A', since 65 is the ASCII value of 'A'. All previous pointers, chP, (chP + 1) and
    (chP + 2) should read null character, int int is stored in this way in memory:
    | 0 | 0 | 0 | 65 |
    Let's see what actually happens.
  */
  cout << *chP << endl;
  cout << *(chP + 1) << endl;
  cout << *(chP + 2) << endl;
  cout << *(chP + 3) << endl;

  /*
    | 65 | 0 | 0 | 0 |

    However, it looks like the first byte stores 65 instead of the last one. So, we can say that
    int is stored in reverse order in the computer memory (least significant bit first). This type
    of memory sturcture is called "Little Endian" since we're keeping the little end first.
    Majority of computers these days are little endian systems, as it adds some performance
    benefit. Simce most calculations are done in least significant bits, and most significant bits
    remain unchanged for most of the time, keeping the least significant bits first gives some
    performance benefit.
  */

  return 0;
}
