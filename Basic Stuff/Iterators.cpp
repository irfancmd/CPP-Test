#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec {5, 4, 23, 1, 89, 5, 2};

    std::vector<int>::iterator it = vec.begin();

    // Iterators are programmed in the standard library to mimick the behaviour of pointers. They prove abstaction in a way
    // that we don't need to know the internal structure of the container
    // Note: The 'end()' iterator points after the last element, not at the last element.
    while(it != vec.end())
    {
        std::cout << *it << std::endl;

        it++;
    }

    return 0;
}