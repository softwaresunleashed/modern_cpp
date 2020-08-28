// 2.9.cpp
#include <iostream>

int print_type_info(const int& t) {
    return t + 1;
}

double print_type_info(const double& t) {
    return t + 0.001;
}

int main() {
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}

