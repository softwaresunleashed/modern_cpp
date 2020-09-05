// 3.3.cpp - Lambda expression (Expression Capture - rvalue)

#include <iostream>

void lambda_expression_capture() {
    auto important = std::make_unique<int>(1);

    // Lambda expression capturing rvalue for v2 and function parameter x & y
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int { 
        return x+y+v1+(*v2);
    };
 
    std::cout << add(3,4) << std::endl;
}

int main()
{
    lambda_expression_capture();
}
