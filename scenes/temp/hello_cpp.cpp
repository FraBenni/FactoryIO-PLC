#include <iostream>

extern "C"
{
    void hello_cpp();
}

void hello_cpp()
{
    std::cout << "Hello from cpp!" << std::endl;
}
