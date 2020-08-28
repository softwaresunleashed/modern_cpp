// 2.11.cpp - Recursion way to print variable number of parameters

#include <iostream> 

// Recursive template function 
template<typename T0> void printf1(T0 value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Ts> 
void printf1(T value, Ts... args) {
    std::cout << value << std::endl;
    printf1(args...); 
}

// Variable parameter template expansion
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << std::endl;
    if constexpr (sizeof...(t) > 0)
        printf2(t...);
}

int main() {
    printf1(1, 2, "123", 1.1); 
    return 0;
}
