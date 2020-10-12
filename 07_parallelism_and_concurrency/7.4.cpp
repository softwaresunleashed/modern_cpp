// 7.4.cpp - asynchornous thread result using std::future<>

#include <iostream>
#include <thread>
#include <future>

int main() {

    // pack a lambda expression that returns 7 into a std::packaged_task
    std::packaged_task<int()> task([](){
        return 7;
    });

    // get the future of task
    std::future<int> result = task.get_future();
    std::thread(std::move(task)).detach();
    std::cout << "waiting...";
    result.wait(); // block until future has arrived

    // output result
    std::cout << "done!" << std:: endl
              << "future result is " << result.get() << std::endl;
    return 0;
}
