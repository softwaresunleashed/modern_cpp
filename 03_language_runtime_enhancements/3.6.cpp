// 3.6.cpp

#include <functional>
#include <iostream>

int foo(int para) {
    return para;
}

int main() {
    // std::function wraps a function that take int paremeter and returns int value 
    std::function<int(int)> func = foo;

    int important = 10;

    std::function<int(int)> func2 = [&](int value) -> int {
        return 1+value+important;
    };
    
    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;
}
