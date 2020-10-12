// 7.8.cpp - Checking if atomic operation is possible - is_lock_free()

#include <atomic>
#include <iostream>

struct A {
    float       x;
    int         y;
    long long   z;
};

int main() {
    std::atomic<A> a;

    // std::boolalpha converts 1->true   or   0->false
    std::cout << std::boolalpha << a.is_lock_free() << std::endl;

    return 0;
}
