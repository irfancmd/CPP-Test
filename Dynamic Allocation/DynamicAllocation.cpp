#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  /*
    C++ introduced the "new" keyword which tells the language to create an object or primitive
    to the "Heap" instead of the "Stack".
  */

  // "new" returns a pointer to the address of the heap where that int is created
  int* n = new int;
  *n = 10; // Data will be stored in the heap

  cout << *n << endl;

  int* nums = new int[100];
  nums[0] = 50;

  cout << nums[0] << endl;

  /*
    Remember: If we use local variables stored in stack, they get deallocated automatically
    when they go out of scope. However, that DOES NOT happen to HEAP varables. Unless we
    deallocate the heap memory manually, they never get deleted. So, if we use heap variables,
    we must deallocate them when we're done.
  */

  for(int i = 0; i < 100; ++i)
  {
    // In each iteration, 4 bytes will be allocated for "num". At the end of the iteration,
    // "num" will go out of sope and the 4 bytes will be freed. This process will repeat for
    // 100 times.
    int num = 10;
  }

  for(int i = 0; i < 100; ++i)
  {
    // Here, we're using a heap variable, so at the end of iteration, the 4 bytes in the heap
    // allocated for it WILL NOT BE FREED, unless we manually delete it. So, if we forget to
    // free this memory, 4 bytes will keep getting allocated over and over again and we may
    // run out of available heap memory.
    int* num = new int;
    *num = 10;

    // Since we dynamically allocated "num", we must free it manually when we're done.
    delete num;
  }

  // Common question: How much memory does this statement will take:
  // Ans: 12 byte. 8 bytes will be allocated in "Stack" to store the pointer variable on stack
  // for a typical 64 bit machine. Then 4 bytes will be allocated in "Heap" for the int
  // data itself. Rememebr, "delete" statement only clears the memory in the heap section. Since
  // the 8 bytes for storing the pointer is allocated in static manner, it will get deleted
  // automatically when it will go out of scope, so we don't have to worry about it.
  int* a = new int;

  return 0;
}
