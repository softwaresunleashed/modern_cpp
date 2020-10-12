// 9.2.cpp - exception handling with / without noexcept

#include <iostream>

void may_throw() {
    throw true;
}

auto non_block_throw = []{
    may_throw();
};

void no_throw() noexcept {
    return;
}

auto block_throw = []() noexcept {
    no_throw();
};


int main()
{
    try {
        may_throw();
    } catch (...) {
        std::cout << "exception captured from my_throw()" << std::endl;
    }

    try {
        non_block_throw();
    } catch (...) {
        std::cout << "exception captured from non_block_throw()" << std::endl;
    }

    try {
        block_throw();
    } catch (...) {
        std::cout << "exception captured from block_throw()" << std::endl;
    }

    return 0;
}
