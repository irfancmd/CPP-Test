#include <iostream>
#include <string>

// In C++, templates are processed by compilers, not at runtime like some other languages
// Note: The keyword 'typename' can also be interchanged with the keyword 'class'
template<typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template<typename T1, typename T2>
void foo(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

int main()
{
    std::cout << max<int>(3, 5) << std::endl;
    // Some compilers can also determine the type by themselves.
    std::cout << max(3, 5) << std::endl;

    foo<double, std::string>(5, "Apples");

    return 0;
}