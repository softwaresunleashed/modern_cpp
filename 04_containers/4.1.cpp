// 4.1.cpp

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    std::cout << "size:" << v.size() << std::endl; // output 0
    std::cout << "capacity:" << v.capacity() << std::endl; // output 0
    return 0;
}
