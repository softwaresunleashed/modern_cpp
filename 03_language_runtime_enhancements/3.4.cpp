// 3.4.cpp - Generic Lambda

#include <iostream>

void lambda_generic() {
    // generic lamba - using auto keyword parameters of autonomous function
    auto generic = [](auto x, auto y) {
        return x+y; 
    };

    std::cout << generic(1, 2) << std::endl;
    std::cout << generic(1.1, 2.2) << std::endl;
}

int main()
{
    lambda_generic();
}
