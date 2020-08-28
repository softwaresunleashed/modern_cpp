// 2.13.cpp - Delegate Constructor example

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

int main() {
    Base b(2);

    std::cout << "Value 1 = " << b.value1 << std::endl; 
    std::cout << "Value 2 = " << b.value2 << std::endl;
}
