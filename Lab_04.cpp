#include <iostream>

int main()
{

    std::cout << "Enter a char: ";
    char c;
    std::cin >> c;

    if (c >= 'A' && c <= 'Z')
    {
        std::cout << "Uppercase letter" << std::endl;
    }
    else if (c >= 'a' && c <= 'z')
    {
        std::cout << "Lowercase letter" << std::endl;
    }
    else if (c >= '0' && c <= '9')
    {
        std::cout << "Digit" << std::endl;
    }
    else
    {
        std::cout << "Special character" << std::endl;
    }
}