// 3.1.cpp - Lambda expression (Value Capture)

#include <iostream>

void lambda_value_capture() { 
    int value = 1;
   
    // Lambda Anonymous function
    auto copy_value = [value] { 
        return value;
    };

    value = 100;
    
    // Anonymous function invocation - copy_value()
    auto stored_value = copy_value();

    std::cout << "stored_value = " << stored_value << std::endl; 
    // At this moment, stored_value == 1, and value == 100.
    // Because copy_value has copied when its was created.
}

int main()
{
    lambda_value_capture();
}
