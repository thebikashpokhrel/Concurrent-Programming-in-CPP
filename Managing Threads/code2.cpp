#include <iostream>
#include <thread>

class abc
{
public:
    int &i;

    abc(int &i_) : i(i_) {};

    void operator()()
    {
        std::cout << "New thread is running in background\n";
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Sleep for 2 seconds to simulate background thread is actually exeucted
        // Trying to access i gives incorrect result as reference to i gets destroyed once parent thread completes execution
        std::cout << "Value of i is " << i << std::endl;
    }
};

int main()
{
    std::thread parent_thread([]()
                              {
        int some_local_state = 4;
        abc func(some_local_state);
        std::thread child_thread(func); 

        child_thread.detach(); //This runs independently of parent thread in background
        std::cout<<"Parent thread is running"<<std::endl; 
        std::cout<<"Parent thread is completed"<<std::endl; });

    parent_thread.join(); // Main thread waits until parent thread is completed
    std::cout << "Main thread is also running" << std::endl;
    return 0;
}