#include <iostream>

namespace space
{
    template <typename T>
    T max(T a, T b)
    {
        return a > b ? a : b;
    }
}

int main()
{
    int i1 = 5, i2 = 12;
    double d1 = 4.12, d2 = 5.61;
    std::string s1 = "Hello", s2 = "MyFriend";

    std::cout << "std::max - " << std::max(i1, i2) << std::endl;
    std::cout << "space::max - " << space::max(i1, i2) << std::endl;
    std::cout << std::endl;

    std::cout << "std::max - " << std::max(d1, d2) << std::endl;
    std::cout << "space::max - " << space::max(d1, d2) << std::endl;
    std::cout << std::endl;

    std::cout << "std::max - " << std::max(s1, s2) << std::endl;
    std::cout << "space::max - " << space::max(s1, s2) << std::endl;
    std::cout << std::endl;
    return 0;
}