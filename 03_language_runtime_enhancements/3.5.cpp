// 3.5.cpp - Lambda function invocation & Lambda as function pointer

#include <iostream>

using foo = void(int); // function pointer declaration

void functional(foo f) {
    f(1);
}

int main() {

    // Lambda expressioni declaration
    auto f = [](int value) {
        std::cout << value << std::endl;
    };
    
    functional(f);  // call by function pointer 
    f(1);           // call by lambda expression 

    return 0;
}
