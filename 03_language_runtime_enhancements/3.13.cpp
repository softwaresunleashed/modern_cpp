// 3.13.cpp

#include <iostream>
#include <utility>

void reference(int& v) {
    std::cout << "lvalue reference" << std::endl;
}

void reference(int&& v) {
    std::cout << "rvalue reference" << std::endl;
}

template <typename T>
void pass(T&& v) {
    std::cout << "          normal param passing: ";
    reference(v);
}

int main() {
    std::cout << "rvalue pass:" << std::endl;
    pass(1);

    std::cout << "lvalue pass:" << std::endl; 
    int l = 1;
    pass(l);

    return 0;
}
