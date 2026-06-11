#include <iostream>
#include <string>

int main()
{
    while (true) {
        std::string name;

        std::cout << "Enter your name: ";
        std::getline(std::cin, name);

        std::cout << "Hello, " << name << "!" << std::endl;
    }

    return 0;
}