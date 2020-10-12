// 7.1.cpp

#include <iostream>
#include <thread>

int main() {
    // define the thread and its body using lambda expression
    std::thread t([](){
        std::cout << "hello world." << std::endl;
    });

    // wait for thread to finish
    t.join();
    return 0;
}
