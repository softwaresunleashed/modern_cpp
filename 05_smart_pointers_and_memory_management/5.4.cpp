// 5.4.cpp - case of destructor not called due to reference count non-zero. (memory leak)

#include <iostream>
#include <memory>

class A;
class B;

class A {
public:
    std::shared_ptr<B> pointer;

    ~A() {
        std::cout << "A was destroyed" << std::endl;
    }
};

class B {
public:
    std::shared_ptr<A> pointer;

    ~B() {
        std::cout << "B was destroyed" << std::endl;
    }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->pointer = b;
    b->pointer = a;

    // Destructor of both a & b are not called as reference count is 2 (and not zero) while leaving scope.
    return 0;
}
