#include <iostream>
#include <vector>
#include "mono_point.hpp"

class MonoTest {
public:
    MonoTest(int s) { }
    char a[3] = {2, 3, 4};
    
    inline char& a_a(int n) { return a[n]; }
};


int main()
{
    int a[3][3] = {0};
    std::cout << a[0][0] << std::endl;
    std::cout << a[0][1] << std::endl;
    std::cout << a[1][0] << std::endl;
    std::cout << a[1][1] << std::endl;
}

