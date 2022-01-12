#include <iostream>
#include <vector>
#include <algorithm>

struct SquareFunctor
{
    void operator()(int x)
    {
        std::cout << x * x << std::endl;
    }
};

void squareFunction(int x)
{
    std::cout << x * x << std::endl;
}

int main()
{
    std::vector<int> vec{4, 1, 5, 12, 5, 12, 53, 59};

    // for_each applies a funtion to all the elements of a container
    // It can be done with several ways
    // 1. Functors or funciton objects
    SquareFunctor square;
    std::for_each(vec.begin(), vec.end(), square);
    std::cout << std::endl;

    // 2. Function pointers
    std::for_each(vec.begin(), vec.end(), squareFunction);
    std::cout << std::endl;

    // 3. Lambda expressions
    std::for_each(vec.begin(), vec.end(), [](int x)
                  { std::cout << x * x << std::endl; });
    std::cout << std::endl;

    return 0;
}