// 5.5.cpp - getting rid of memory leak by using std::weak_ptr

#include <iostream>
#include <memory>

class A;
class B;

class A {
public:
    // Declaring pointer as weak reference so there is no round referencing issue that leads to memory leaks
    std::weak_ptr<B> pointer;

    ~A() {
        std::cout << "A was destroyed" << std::endl;
    }
};

class B {
public:
    // Declaring pointer as weak reference so there is no round referencing issue that leads to memory leaks
    std::weak_ptr<A> pointer;

    ~B() {
        std::cout << "B was destroyed" << std::endl;
    }
};

int main() {
    // Creating a strong reference pointer to objects of class A & B
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    // Creating a circular dependency
    a->pointer = b;
    b->pointer = a;

    return 0;
    // Destructor of both a & b are now called.
}
