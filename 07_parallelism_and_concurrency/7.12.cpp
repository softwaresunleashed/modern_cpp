// 7.12.cpp

#include <iostream>
#include <thread>
#include <vector>

std::atomic<int> counter = {0};
std::vector<std::thread> vt;

int main() {

    for (int i = 0; i < 100; ++i) {
        vt.emplace_back([]() {
            counter.fetch_add(1, std::memory_order_seq_cst);
        });
    }

    for (auto& t : vt) {
        t.join();
    }

    std::cout << "current counter:" << counter << std::endl;
}
