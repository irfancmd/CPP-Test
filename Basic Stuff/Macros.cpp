#include <iostream>

// Macros are processed by the pre-processor; not the C++ compiler. It just replaces the name of the macro with the defined syntax
// This macro can be used to mimick a generic implementation of a 'max' function. Note it's NOT a function. It will just copy the syntax right into the code
// Note we should wrap macro expressions with parentheses to avoid unexpeced behaviour or syntax errors
#define MAX(a, b) ((a > b ) ? a: b)
// Below is an example of a bad macro. Since it's not wrapped by parentheses, it will produce wrong answer when it gets copied into the code
#define BAD_SQUARE(a) a*a
// Below is the fixed version of the above macro
#define GOOD_SQUARE(a) (a*a)

int main()
{

    // Testing the MAX macro
    std::cout << MAX(3, 5) << std::endl;
    std::cout << MAX(3.1416, 1.792) << std::endl;

    // Testing the BAD_SQUARE macro
    // In this case it works just fine
    std::cout << BAD_SQUARE(5) << std::endl;
    // But in this case, it doesn't work. Because it becomes "100/5*5"
    std::cout << 100/BAD_SQUARE(5) << std::endl;

    // Testing the GOOD_SQUARE macro
    std::cout << GOOD_SQUARE(5) << std::endl;
    // This macro works because it becomes "100/(5*5)"
    std::cout << 100/GOOD_SQUARE(5) << std::endl;
    return 0;
}