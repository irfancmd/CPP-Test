#include <iostream>
#include <string>

template <typename T>
class Person
{
public:
    Person(std::string personName, T personAge) : name{personName}, age{personAge} {}

    std::string getName() { return name; };
    T getAge() { return age; };

private:
    std::string name;
    T age;
};

int main()
{
    Person<int> person01("Abul", 25);
    std::cout << person01.getName() << " : " << person01.getAge() << std::endl;

    Person<double> person02("Kuddus", 32.5);
    std::cout << person02.getName() << " : " << person02.getAge() << std::endl;

    Person<std::string> person03("Rahim", "Twenty eight");
    std::cout << person03.getName() << " : " << person03.getAge() << std::endl;

    return 0;
}