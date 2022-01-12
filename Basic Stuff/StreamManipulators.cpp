#include <iostream>
#include <iomanip>

int main()
{
    // Telling cout to output booleans as 'true' or 'false' instead of '1' and '0'
    std::cout << std::boolalpha;
    std::cout << (10 == 10) << std::endl;
    std::cout << (10 == 20) << std::endl;
    // Resetting the io manipulator
    std::cout << std::noboolalpha;
    std::cout << (10 == 10) << std::endl;
    std::cout << (10 == 20) << std::endl;

    // Outputting numbers in different bases
    int aNumber = 256;
    std::cout << std::oct << aNumber << std::endl;
    std::cout << std::hex << aNumber << std::endl;
    // Resetting cout back to outputting decimal
    std::cout << std::dec;

    // Formatting floating points
    double aFloatNumber = 12345.678905;
    // By default, cout sets the precision to 6 including the whole portion
    std::cout << aFloatNumber << std::endl;
    // The 'fixed' manupulator makes sure cout starts counting precision after the decimal point unlike the default behaviour
    std::cout << std::setprecision(10)
              << std::fixed
              << aFloatNumber << std::endl;
    // Print floating point in scientific notation
    std::cout << std::scientific << aFloatNumber << std::endl;

    // These formatting properties only affect the immediate output. Rest will be unaltered
    // Output Width
    int anotherNumber = 12345;
    std::string aString = "Hello!";

    std::cout << std::setw(10)
              << anotherNumber << aString << std::endl;
    // Width + Left Justification
    std::cout << std::setw(10)
              << std::left
              << anotherNumber
              << std::setw(10)
              << std::left
              << aString << std::endl;
    // Custom fill width rather than blank space
    std::cout << std::setw(10)
              << std::left
              << std::setfill('-')
              << anotherNumber
              << std::setw(10)
              << std::left
              << std::setfill('-')
              << aString << std::endl;

    return 0;
}