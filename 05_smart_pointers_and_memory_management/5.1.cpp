// 5.1.cpp - Shared Pointer declaration and usage

#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i) {
    (*i)++;
}

int main() {
    // auto pointer = new int(10);              // illegal, no direct assignment

    // Constructed a std::shared_ptr
    auto pointer = std::make_shared<int>(10);
    foo(pointer);

    std::cout << *pointer << std::endl;         // 11
    // The shared_ptr will be destructed before leaving the scope

    return 0;
}
