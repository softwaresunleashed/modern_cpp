// 7.9.cpp

#include <atomic>
#include <vector>
#include <iostream>
#include <thread>

std::atomic<int> counter = {0};
std::vector<std::thread> vt;

int main(){

    for (int i = 0; i < 100; ++i) {
        vt.emplace_back([](){
            counter.fetch_add(1, std::memory_order_relaxed);
        });
    }

    for (auto& t : vt) {
            t.join();
    }

    std::cout << "current counter:" << counter << std::endl;
}
