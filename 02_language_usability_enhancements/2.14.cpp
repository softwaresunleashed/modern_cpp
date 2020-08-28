// 2.14.cpp - Inheritance constructor via "using" keyword

#include <iostream>
class Base { 
    public:
        int value1;
        int value2;
    
        Base() {
            value1 = 1;
        }

        Base(int value) : Base() { // delegate Base() constructor 
            value2 = value;
        } 
};

class Subclass : public Base { 
    public:
        using Base::Base; // inheritance constructor 
};

int main() {
    Subclass s(3);
    
    std::cout << "Value 1 = " << s.value1 << std::endl;
    std::cout << "Value 2 = " << s.value2 << std::endl; 
}
