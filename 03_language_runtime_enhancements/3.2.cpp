// 3.2.cpp - Lambda expression (Reference Capture)

#include <iostream>


void lambda_reference_capture() {
    int value = 1;

     // Lambda Anonymous function - Pass by reference &value
    auto copy_value = [&value] {
        return value;
    };

    value = 100;

    // Anonymous function invocation - copy_value()
    auto stored_value = copy_value();

    std::cout << "stored_value = " << stored_value << std::endl; 
    // At this moment, stored_value == 100, value == 100.
    // Because copy_value stores reference
    std::cout << "value = " << value << std::endl; 
}

int main()
{
    lambda_reference_capture();
}
