// 7.10.cpp - Memory Order Producer / Consumer Memory Order

#include <iostream>
#include <thread>

int main(){
    std::atomic<int*> ptr;
    int v;

    // Create and start a producer thread
    std::thread producer([&]() {
        int* p = new int(42);
        v = 1024;
        ptr.store(p, std::memory_order_release);
    });

    // Create and start a consumer thread
    std::thread consumer([&]() {
        int* p;
        while(!(p = ptr.load(std::memory_order_consume)));
        std::cout << "p: " << *p << std::endl;
        std::cout << "v: " << v << std::endl;
    });

    // Wait for producer and consumer thread to finish
    producer.join();
    consumer.join();
}
