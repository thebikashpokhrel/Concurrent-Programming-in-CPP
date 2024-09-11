#include <iostream>
#include <thread>

void helloworld()
{
    std::cout << "Hello world from new thread\n";
}

int main()
{
    std::thread hw(helloworld);
    std::cout << "Hello world from main thread\n";
    hw.join();
    return 0;
}