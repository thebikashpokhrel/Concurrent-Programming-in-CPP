#include <iostream>
#include <thread>

using namespace std;

class background_task
{
public:
    void operator()(int x) const
    {
        cout << "Function called with variable value x = " << x << endl;
    }
};

int main()
{
    background_task b; // Functor object
    thread my_thread{background_task(), 4};

    my_thread.join();

    // // Using Lamda Expression
    // thread t([]()
    //          { cout << "Function called with variable value x = " << 4 << endl; });

    // t.join();
    return 0;
}
