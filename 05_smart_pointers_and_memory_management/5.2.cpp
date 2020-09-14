// 5.2.cpp - shared_ptr reference count and reset

#include <iostream>
#include <memory>

int main() {
    auto pointer    = std::make_shared<int>(10);
    auto pointer2   = pointer;          // reference count+1
    auto pointer3   = pointer;          // reference count+1
    int *p          = pointer.get();    // no increase of reference count

    std::cout << "pointer.use_count()  = " << pointer.use_count() << std::endl;     // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 3
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 3

    pointer2.reset();
    std::cout << "reset pointer2:" << std::endl;
    std::cout << "pointer.use_count()  = " << pointer.use_count() << std::endl;     // 2
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 0 , pointer 2 has been reset
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 2

    pointer3.reset();
    std::cout << "reset pointer3:" << std::endl;
    std::cout << "pointer.use_count()  = " << pointer.use_count() << std::endl;     // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 0, pointer 3 has been reset

    return 0;
}
