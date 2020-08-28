// 2.12.cpp
#include <iostream>

template<typename ... T> 
auto sum(T ... t) {
    return (t + ...);
}

int main() {
    std::cout << "Total Sum = " << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
}
